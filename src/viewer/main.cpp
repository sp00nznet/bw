// Black & White Mesh Browser
// Win32 + OpenGL 2.1 viewer for .L3D mesh files and .G3D mesh archives
//
// Usage: bw_viewer.exe <path_to_l3d_or_g3d_file>
//
// Controls:
//   Left mouse drag  — orbit camera
//   Right mouse drag — zoom
//   Mouse wheel      — zoom
//   W/A/S/D          — pan camera
//   R                — reset camera
//   Tab              — toggle wireframe
//   Left/Right       — previous/next mesh (G3D mode)
//   Home/End         — first/last mesh
//   Escape           — quit

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

#include "l3d_loader.h"
#include "g3d_loader.h"
#include "lnd_loader.h"
#include "script_parser.h"
#include "game_loop.h"
#include "mesh_names.h"

#include <black/LHVMObjects.h>
#include <black/Object.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

// GL extension constants
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2

typedef void (APIENTRY *PFNGLCOMPRESSEDTEXIMAGE2DPROC)(
    GLenum target, GLint level, GLenum internalformat,
    GLsizei width, GLsizei height, GLint border,
    GLsizei imageSize, const void* data);
static PFNGLCOMPRESSEDTEXIMAGE2DPROC pfnGlCompressedTexImage2D = nullptr;

// ============================================================================
// Globals
// ============================================================================

static bw::L3DModel    g_single_model;
static bw::G3DArchive  g_archive;
static bw::Landscape   g_landscape;
static bw::LevelScript g_script;
static bw::GameState   g_game;
static bool            g_archive_mode = false;
static bool            g_terrain_mode = false;
static bool            g_world_mode   = false;
static bool            g_game_mode    = false;
static int             g_current_mesh = 0;
static bw::L3DModel*  g_active_model = nullptr;
static int             g_mouse_x = 0, g_mouse_y = 0;
static bool            g_lmb_down = false, g_rmb_down = false;

static std::map<uint32_t, GLuint> g_gl_textures; // skin_id → GL texture

static bool         g_wireframe  = false;
static float        g_cam_yaw    = 30.0f;
static float        g_cam_pitch  = 20.0f;
static float        g_cam_dist   = 5.0f;
static float        g_cam_x      = 0.0f;
static float        g_cam_y      = 0.0f;
static float        g_cam_z      = 0.0f;
static bool         g_dragging   = false;
static bool         g_zooming    = false;
static int          g_last_mx    = 0;
static int          g_last_my    = 0;
static int          g_width      = 1280;
static int          g_height     = 720;
static HWND         g_hwnd       = nullptr;

// ============================================================================
// Texture upload
// ============================================================================

static void UploadTextures(const bw::G3DArchive& archive) {
    if (!pfnGlCompressedTexImage2D) {
        printf("WARNING: glCompressedTexImage2D not available, no textures\n");
        return;
    }

    for (const auto& [id, tex] : archive.textures) {
        GLuint gl_tex;
        glGenTextures(1, &gl_tex);
        glBindTexture(GL_TEXTURE_2D, gl_tex);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        GLenum format;
        int block_size;
        if (tex.type == 1) {
            format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
            block_size = 8;
        } else {
            format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
            block_size = 16;
        }

        int w = tex.width, h = tex.height;
        int data_size = ((w + 3) / 4) * ((h + 3) / 4) * block_size;

        if (static_cast<size_t>(data_size) <= tex.texel_data.size()) {
            pfnGlCompressedTexImage2D(GL_TEXTURE_2D, 0, format,
                                       w, h, 0, data_size, tex.texel_data.data());
        }

        g_gl_textures[id] = gl_tex;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    printf("Uploaded %zu GL textures\n", g_gl_textures.size());
}

// ============================================================================
// Camera / model management
// ============================================================================

static void ResetCamera() {
    if (g_game_mode) {
        g_cam_x = (g_game.terrain.min_x + g_game.terrain.max_x) * 0.5f;
        g_cam_y = (g_game.terrain.min_y + g_game.terrain.max_y) * 0.5f;
        g_cam_z = (g_game.terrain.min_z + g_game.terrain.max_z) * 0.5f;
        g_cam_dist = 150.0f; // Close enough to see entities
        g_cam_yaw = 30.0f;
        g_cam_pitch = 40.0f;
        return;
    }
    if (g_terrain_mode) {
        g_cam_x = (g_landscape.min_x + g_landscape.max_x) * 0.5f;
        g_cam_y = (g_landscape.min_y + g_landscape.max_y) * 0.5f + g_landscape.GetExtent() * 0.1f;
        g_cam_z = (g_landscape.min_z + g_landscape.max_z) * 0.5f;
        g_cam_dist = g_landscape.GetExtent() * 0.5f;
        g_cam_yaw = 30.0f;
        g_cam_pitch = 30.0f;
        return;
    }
    if (!g_active_model) return;
    g_cam_x = (g_active_model->min_x + g_active_model->max_x) * 0.5f;
    g_cam_y = (g_active_model->min_y + g_active_model->max_y) * 0.5f;
    g_cam_z = (g_active_model->min_z + g_active_model->max_z) * 0.5f;
    g_cam_dist = g_active_model->GetExtent() * 2.0f;
    if (g_cam_dist < 1.0f) g_cam_dist = 1.0f;
    g_cam_yaw = 30.0f;
    g_cam_pitch = 20.0f;
}

static void UpdateTitle() {
    char title[512];
    if (g_archive_mode && g_active_model) {
        const char* name = (g_current_mesh < g_mesh_name_count) ?
            g_mesh_names[g_current_mesh] : "???";
        snprintf(title, sizeof(title),
                 "B&W Mesh Browser — [%d/%zu] %s (%u verts, %u tris)",
                 g_current_mesh, g_archive.MeshCount(), name,
                 g_active_model->TotalVertices(), g_active_model->TotalTriangles());
    } else if (g_active_model) {
        snprintf(title, sizeof(title),
                 "B&W Viewer — %s (%u verts, %u tris)",
                 g_active_model->filename.c_str(),
                 g_active_model->TotalVertices(), g_active_model->TotalTriangles());
    } else {
        snprintf(title, sizeof(title), "B&W Viewer — (no mesh)");
    }
    SetWindowTextA(g_hwnd, title);
}

static void SelectMesh(int index) {
    if (!g_archive_mode) return;
    int count = static_cast<int>(g_archive.MeshCount());
    if (count == 0) return;

    // Wrap around
    index = ((index % count) + count) % count;

    // Find next valid mesh if this one is empty
    for (int tries = 0; tries < count; ++tries) {
        if (!g_archive.meshes[index].submeshes.empty()) break;
        index = (index + 1) % count;
    }

    g_current_mesh = index;
    g_active_model = &g_archive.meshes[g_current_mesh];
    ResetCamera();
    UpdateTitle();
}

// ============================================================================
// OpenGL rendering
// ============================================================================

static void SetupGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glClearColor(0.15f, 0.15f, 0.2f, 1.0f);

    // Alpha test for DXT3 cutout transparency (fences, leaves, etc.)
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.5f);

    // Blending for smooth alpha edges
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float light_pos[]  = { 1.0f, 2.0f, 1.5f, 0.0f };
    float light_amb[]  = { 0.25f, 0.25f, 0.25f, 1.0f };
    float light_diff[] = { 0.85f, 0.85f, 0.85f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diff);

    // Load compressed texture extension
    pfnGlCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)
        wglGetProcAddress("glCompressedTexImage2D");
}

static void RenderModel(const bw::L3DModel& model) {
    static const float colors[][3] = {
        {0.8f, 0.6f, 0.4f}, {0.4f, 0.7f, 0.8f}, {0.7f, 0.8f, 0.4f},
        {0.8f, 0.4f, 0.6f}, {0.6f, 0.4f, 0.8f}, {0.4f, 0.8f, 0.6f},
    };
    int color_idx = 0;

    for (const auto& sub : model.submeshes) {
        for (const auto& prim : sub.primitives) {
            // Try to bind texture
            bool textured = false;
            if (prim.material_type >= 2) { // textured material types
                auto it = g_gl_textures.find(prim.skin_id);
                if (it != g_gl_textures.end()) {
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D, it->second);
                    glColor3f(1.0f, 1.0f, 1.0f);
                    textured = true;
                }
            }

            if (!textured) {
                glDisable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, 0);
                if (prim.color != 0 && prim.color != 0xFFFFFFFF) {
                    float r = ((prim.color >> 16) & 0xFF) / 255.0f;
                    float g = ((prim.color >>  8) & 0xFF) / 255.0f;
                    float b = ((prim.color >>  0) & 0xFF) / 255.0f;
                    glColor3f(r, g, b);
                } else {
                    const float* c = colors[color_idx % 6];
                    glColor3f(c[0], c[1], c[2]);
                }
            }
            color_idx++;

            glBegin(GL_TRIANGLES);
            for (const auto& tri : prim.triangles) {
                for (int k = 0; k < 3; ++k) {
                    uint16_t idx = (&tri.i0)[k];
                    if (idx >= prim.vertices.size()) continue;
                    const auto& v = prim.vertices[idx];
                    glTexCoord2f(v.u, v.v);
                    glNormal3f(v.nx, v.ny, v.nz);
                    glVertex3f(v.px, v.py, v.pz);
                }
            }
            glEnd();
        }
    }
    glDisable(GL_TEXTURE_2D);
}

static void RenderTerrain(const bw::Landscape& land) {
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < land.indices.size(); i += 3) {
        for (int k = 0; k < 3; ++k) {
            const auto& v = land.vertices[land.indices[i + k]];
            glColor3f(v.r, v.g, v.b);
            glNormal3f(v.nx, v.ny, v.nz);
            glVertex3f(v.x, v.y, v.z);
        }
    }
    glEnd();
}

static float GetTerrainHeight(float wx, float wz) {
    // Simple height lookup from terrain vertices (nearest vertex)
    if (g_landscape.vertices.empty()) return 0;
    float best_dist = 1e30f;
    float best_y = 0;
    // Sample a subset for performance
    size_t step = std::max<size_t>(1, g_landscape.vertices.size() / 10000);
    for (size_t i = 0; i < g_landscape.vertices.size(); i += step) {
        const auto& v = g_landscape.vertices[i];
        float dx = v.x - wx, dz = v.z - wz;
        float d = dx*dx + dz*dz;
        if (d < best_dist) { best_dist = d; best_y = v.y; }
    }
    return best_y;
}

static void RenderWorldEntities() {
    for (const auto& ent : g_script.entities) {
        if (ent.mesh_id < 0 || ent.mesh_id >= static_cast<int>(g_archive.meshes.size()))
            continue;
        const auto& model = g_archive.meshes[ent.mesh_id];
        if (model.submeshes.empty()) continue;

        float y = GetTerrainHeight(ent.x, ent.z);

        // Skip entities in water (altitude near zero = ocean)
        if (y < 2.0f) continue;

        glPushMatrix();
        glTranslatef(ent.x, y, ent.z);
        if (ent.angle != 0) glRotatef(ent.angle * 180.0f / 3.14159265f, 0, 1, 0);
        if (ent.scale != 1.0f && ent.scale > 0) glScalef(ent.scale, ent.scale, ent.scale);

        RenderModel(model);
        glPopMatrix();
    }
}

static void RenderGameEntities() {
    for (size_t i = 0; i < g_game.entities.size(); ++i) {
        const auto& ent = g_game.entities[i];
        if (!ent.alive) continue;
        if (ent.mesh_id < 0 || ent.mesh_id >= static_cast<int>(g_game.meshes.meshes.size()))
            continue;
        const auto& model = g_game.meshes.meshes[ent.mesh_id];
        if (model.submeshes.empty()) continue;

        glPushMatrix();
        glTranslatef(ent.x, ent.y, ent.z);
        if (ent.angle != 0) glRotatef(ent.angle * 180.0f / 3.14159265f, 0, 1, 0);
        if (ent.scale != 1.0f && ent.scale > 0) glScalef(ent.scale, ent.scale, ent.scale);

        // Highlight selected/hovered entities
        if (ent.selected) {
            glColor3f(1.0f, 1.0f, 0.5f); // Yellow tint for held
        } else if (static_cast<int>(i) == g_game.hand.hover_entity) {
            glColor3f(0.8f, 1.0f, 0.8f); // Green tint for hover
        }

        RenderModel(model);
        glPopMatrix();
    }

    // Render hand
    if (g_game.hand.is_over_land) {
        float hx = g_game.hand.x;
        float hy = g_game.hand.y + 15.0f;
        float hz = g_game.hand.z;

        // Render the hand mesh
        if (g_game.hand_mesh_id >= 0 &&
            g_game.hand_mesh_id < static_cast<int>(g_game.meshes.meshes.size()) &&
            !g_game.meshes.meshes[g_game.hand_mesh_id].submeshes.empty()) {
            glPushMatrix();
            glTranslatef(hx, hy, hz);
            float hand_scale = g_cam_dist * 0.003f; // Small relative to view
            glScalef(hand_scale, hand_scale, hand_scale);
            glRotatef(g_cam_yaw + 180.0f, 0, 1, 0); // Always face camera
            glRotatef(-60.0f, 1, 0, 0); // Tilt pointing down
            RenderModel(g_game.meshes.meshes[g_game.hand_mesh_id]);
            glPopMatrix();
        }

        // Also draw a ground crosshair for precision
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        float gz = g_game.hand.y + 0.5f; // Just above ground
        float sz = (g_game.hand.hover_entity >= 0) ? 8.0f : 5.0f;
        glColor3f(g_game.hand.hover_entity >= 0 ? 0.0f : 1.0f,
                  1.0f,
                  g_game.hand.hover_entity >= 0 ? 0.0f : 1.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glVertex3f(hx - sz, gz, hz); glVertex3f(hx + sz, gz, hz);
        glVertex3f(hx, gz, hz - sz); glVertex3f(hx, gz, hz + sz);
        glEnd();
        glLineWidth(1.0f);
        glEnable(GL_LIGHTING);
    }
}

static void RenderGrid(float extent) {
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINES);
    float step = extent / 10.0f;
    if (step < 0.1f) step = 0.1f;
    for (float i = -extent; i <= extent; i += step) {
        glVertex3f(i, 0.0f, -extent);
        glVertex3f(i, 0.0f,  extent);
        glVertex3f(-extent, 0.0f, i);
        glVertex3f( extent, 0.0f, i);
    }
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(extent*0.3f,0,0);
    glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,extent*0.3f,0);
    glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,extent*0.3f);
    glEnd();
    glLineWidth(1.0f);
    glEnable(GL_LIGHTING);
}

static void Display() {
    if (!g_active_model && !g_terrain_mode) return;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = static_cast<float>(g_width) / static_cast<float>(g_height);
    gluPerspective(45.0, aspect, 0.1 * g_cam_dist, 200.0 * g_cam_dist);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float rad_yaw   = g_cam_yaw   * 3.14159265f / 180.0f;
    float rad_pitch  = g_cam_pitch * 3.14159265f / 180.0f;
    float eye_x = g_cam_x + g_cam_dist * cosf(rad_pitch) * sinf(rad_yaw);
    float eye_y = g_cam_y + g_cam_dist * sinf(rad_pitch);
    float eye_z = g_cam_z + g_cam_dist * cosf(rad_pitch) * cosf(rad_yaw);
    gluLookAt(eye_x, eye_y, eye_z, g_cam_x, g_cam_y, g_cam_z, 0.0, 1.0, 0.0);

    float light_pos[] = { 0.5f, 1.0f, 0.3f, 0.0f }; // Directional sunlight
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    if (g_world_mode || g_terrain_mode) {
        if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        RenderTerrain(g_landscape);
        if (g_world_mode && !g_game_mode) RenderWorldEntities();
        if (g_game_mode) RenderGameEntities();
        if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else if (g_active_model) {
        float extent = g_active_model->GetExtent();
        if (extent < 1.0f) extent = 1.0f;
        RenderGrid(extent);

        if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        RenderModel(*g_active_model);
        if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

// ============================================================================
// Win32 window
// ============================================================================

static HGLRC g_hrc = nullptr;
static HDC   g_hdc = nullptr;

static bool SetupPixelFormat(HDC hdc) {
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int fmt = ChoosePixelFormat(hdc, &pfd);
    if (!fmt) return false;
    return SetPixelFormat(hdc, fmt, &pfd) != FALSE;
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_SIZE:
        g_width  = LOWORD(lp);
        g_height = HIWORD(lp);
        if (g_height < 1) g_height = 1;
        glViewport(0, 0, g_width, g_height);
        return 0;

    case WM_LBUTTONDOWN:
        g_lmb_down = true;
        if (g_game_mode) {
            // Latch the click for the LHVM so GAME_THING_CLICKED /
            // POSITION_CLICKED / GET_OBJECT_CLICKED can fire from scripts.
            int hover = g_game.hand.hover_entity;
            if (hover >= 0 && hover < static_cast<int>(g_game.core_entities.size())) {
                lhvm::NotifyObjectClicked(lhvm::HandleFor(g_game.core_entities[hover]));
            }
            lhvm::NotifyPositionClicked(g_game.hand.x, g_game.hand.y, g_game.hand.z);
        }
        if (g_game_mode && g_game.hand.hover_entity >= 0 && g_game.hand.held_entity < 0) {
            g_game.PickUpEntity(g_game.hand.hover_entity);
        } else {
            g_dragging = true;
            g_last_mx = LOWORD(lp); g_last_my = HIWORD(lp);
            SetCapture(hwnd);
        }
        return 0;
    case WM_RBUTTONDOWN:
        g_rmb_down = true;
        if (g_game_mode && g_game.hand.held_entity >= 0) {
            // Throw held entity in camera forward direction
            float rad_yaw = g_cam_yaw * 3.14159265f / 180.0f;
            g_game.ThrowEntity(-sinf(rad_yaw) * 100.0f, 50.0f, -cosf(rad_yaw) * 100.0f);
        } else {
            g_zooming = true;
            g_last_my = HIWORD(lp);
            SetCapture(hwnd);
        }
        return 0;
    case WM_LBUTTONUP:
        g_lmb_down = false;
        if (g_game_mode && g_game.hand.held_entity >= 0) {
            g_game.DropEntity();
        }
        g_dragging = false; ReleaseCapture(); return 0;
    case WM_RBUTTONUP:
        g_rmb_down = false;
        g_zooming = false; ReleaseCapture(); return 0;

    case WM_MOUSEMOVE:
        g_mouse_x = LOWORD(lp);
        g_mouse_y = HIWORD(lp);
        if (g_dragging) {
            int mx = LOWORD(lp), my = HIWORD(lp);
            g_cam_yaw   += (mx - g_last_mx) * 0.5f;
            g_cam_pitch += (my - g_last_my) * 0.5f;
            g_cam_pitch = std::clamp(g_cam_pitch, -89.0f, 89.0f);
            g_last_mx = mx; g_last_my = my;
        }
        if (g_zooming) {
            int my = HIWORD(lp);
            g_cam_dist *= 1.0f + (my - g_last_my) * 0.005f;
            if (g_cam_dist < 0.1f) g_cam_dist = 0.1f;
            g_last_my = my;
        }
        return 0;

    case WM_MOUSEWHEEL: {
        short delta = GET_WHEEL_DELTA_WPARAM(wp);
        g_cam_dist *= 1.0f - delta * 0.001f;
        if (g_cam_dist < 0.1f) g_cam_dist = 0.1f;
        return 0;
    }

    case WM_KEYDOWN:
        switch (wp) {
        case VK_ESCAPE: PostQuitMessage(0); break;
        case VK_TAB:    g_wireframe = !g_wireframe; break;
        case 'R':       ResetCamera(); break;
        case 'W': case 'S': case 'A': case 'D': {
            // Camera-relative movement
            float rad = g_cam_yaw * 3.14159265f / 180.0f;
            float speed = g_cam_dist * 0.05f;
            float fw_x = -sinf(rad), fw_z = -cosf(rad);
            float rt_x = cosf(rad), rt_z = -sinf(rad);
            if (wp == 'W') { g_cam_x += fw_x * speed; g_cam_z += fw_z * speed; }
            if (wp == 'S') { g_cam_x -= fw_x * speed; g_cam_z -= fw_z * speed; }
            if (wp == 'A') { g_cam_x -= rt_x * speed; g_cam_z -= rt_z * speed; }
            if (wp == 'D') { g_cam_x += rt_x * speed; g_cam_z += rt_z * speed; }
            break;
        }
        case VK_LEFT:  if (g_archive_mode) SelectMesh(g_current_mesh - 1); break;
        case VK_RIGHT: if (g_archive_mode) SelectMesh(g_current_mesh + 1); break;
        case VK_HOME:  if (g_archive_mode) SelectMesh(0); break;
        case VK_END:   if (g_archive_mode) SelectMesh(static_cast<int>(g_archive.MeshCount()) - 1); break;
        case VK_PRIOR: if (g_archive_mode) SelectMesh(g_current_mesh - 10); break; // Page Up
        case VK_NEXT:  if (g_archive_mode) SelectMesh(g_current_mesh + 10); break; // Page Down
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

// ============================================================================
// Entry point
// ============================================================================

int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    if (argc < 2) {
        fprintf(stderr, "Usage: bw_viewer.exe <file.l3d | file.g3d>\n");
        return 1;
    }

    std::string path = argv[1];
    std::string ext = path.substr(path.find_last_of('.') + 1);
    for (auto& c : ext) c = static_cast<char>(tolower(c));

    if (ext == "txt" && argc >= 3 && std::string(argv[2]) == "--play") {
        // Game mode: interactive with hand + entity interaction
        g_game_mode = true;
        g_world_mode = true;
        g_terrain_mode = true;
        if (!g_game.Init(path)) {
            fprintf(stderr, "Failed to init game: %s\n", path.c_str());
            return 1;
        }
        // Copy game data to the globals used by the renderer
        g_landscape = g_game.terrain;
        g_archive = g_game.meshes;
        g_script = g_game.script;
    } else if (ext == "txt") {
        // World viewer mode: load script + terrain + meshes (read-only)
        g_world_mode = true;
        g_terrain_mode = true;

        // Parse the script file
        if (!bw::ParseLevelScript(path, g_script)) {
            fprintf(stderr, "Failed to parse script: %s\n", path.c_str());
            return 1;
        }

        // Derive terrain and mesh paths from script path
        std::string dir = path.substr(0, path.find_last_of("/\\") + 1);
        // Try to find matching .lnd file (Land1.txt → Land1.lnd)
        std::string base = path.substr(0, path.find_last_of('.'));
        std::string lnd_path = base + ".lnd";
        std::string g3d_path = dir + "AllMeshes.g3d";

        printf("World: Loading terrain from %s\n", lnd_path.c_str());
        if (!bw::LoadLND(lnd_path, g_landscape)) {
            fprintf(stderr, "Failed to load terrain: %s\n", lnd_path.c_str());
            return 1;
        }

        printf("World: Loading meshes from %s\n", g3d_path.c_str());
        if (!bw::LoadG3D(g3d_path, g_archive)) {
            fprintf(stderr, "Failed to load meshes: %s\n", g3d_path.c_str());
            return 1;
        }
    } else if (ext == "lnd") {
        // Terrain mode
        g_terrain_mode = true;
        if (!bw::LoadLND(path, g_landscape)) {
            fprintf(stderr, "Failed to load LND: %s\n", path.c_str());
            return 1;
        }
    } else if (ext == "g3d") {
        // Archive mode
        g_archive_mode = true;
        if (!bw::LoadG3D(path, g_archive)) {
            fprintf(stderr, "Failed to load G3D: %s\n", path.c_str());
            return 1;
        }
        g_current_mesh = 0;
        // Find first non-empty mesh
        for (size_t i = 0; i < g_archive.meshes.size(); ++i) {
            if (!g_archive.meshes[i].submeshes.empty()) {
                g_current_mesh = static_cast<int>(i);
                break;
            }
        }
        g_active_model = &g_archive.meshes[g_current_mesh];
    } else {
        // Single L3D file mode
        if (!bw::LoadL3D(path, g_single_model)) {
            fprintf(stderr, "Failed to load L3D: %s\n", path.c_str());
            return 1;
        }
        g_active_model = &g_single_model;
    }

    ResetCamera();

    // Create window
    WNDCLASSA wc = {};
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandleA(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = "BWViewer";
    RegisterClassA(&wc);

    g_hwnd = CreateWindowA("BWViewer", "B&W Mesh Browser",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, g_width, g_height,
        nullptr, nullptr, wc.hInstance, nullptr);

    if (!g_hwnd) { fprintf(stderr, "Failed to create window\n"); return 1; }

    g_hdc = GetDC(g_hwnd);
    if (!SetupPixelFormat(g_hdc)) { fprintf(stderr, "Failed to set pixel format\n"); return 1; }
    g_hrc = wglCreateContext(g_hdc);
    wglMakeCurrent(g_hdc, g_hrc);

    SetupGL();
    glViewport(0, 0, g_width, g_height);

    // Upload textures if we have a G3D archive loaded
    if (g_archive_mode || g_world_mode) {
        UploadTextures(g_archive);
    } else if (g_game_mode) {
        UploadTextures(g_game.meshes);
    }

    ResetCamera();
    UpdateTitle();
    printf("Ready. Controls: LMB=orbit, RMB=zoom, WASD=pan, Tab=wireframe, R=reset");
    if (g_archive_mode) printf(", Left/Right=browse, PgUp/PgDn=skip 10");
    printf(", Esc=quit\n");

    // Main loop
    MSG msg;
    bool running = true;
    while (running) {
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) { running = false; break; }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (!running) break;

        // Game tick — throttle simulation to BW's 10 Hz turn rate so that
        // script OP_WAIT/OP_SLEEP timers and game_turn-driven natives match
        // the original game's pacing. Hand input updates every render frame.
        static double s_sim_accum_ms = 0.0;
        static DWORD  s_last_tick    = GetTickCount();
        DWORD now = GetTickCount();
        s_sim_accum_ms += static_cast<double>(now - s_last_tick);
        s_last_tick = now;
        constexpr double SIM_STEP_MS = 100.0;  // 10 Hz

        if (g_game_mode) {
            g_game.cam_x = g_cam_x;
            g_game.cam_y = g_cam_y;
            g_game.cam_z = g_cam_z;
            g_game.cam_yaw = g_cam_yaw;
            g_game.cam_pitch = g_cam_pitch;
            g_game.cam_dist = g_cam_dist;
            g_game.UpdateHand(g_mouse_x, g_mouse_y, g_width, g_height);

            // Run as many sim steps as elapsed time accumulated, capped
            // to 5 catch-up steps so a stalled frame doesn't snowball.
            int steps = 0;
            while (s_sim_accum_ms >= SIM_STEP_MS && steps < 5) {
                g_game.ProcessTurn();
                s_sim_accum_ms -= SIM_STEP_MS;
                steps++;
            }
            if (s_sim_accum_ms > SIM_STEP_MS * 5)
                s_sim_accum_ms = SIM_STEP_MS;  // drop excess on long stalls
        }

        Display();
        SwapBuffers(g_hdc);
        Sleep(16);
    }

    // Cleanup GL textures
    for (auto& [id, tex] : g_gl_textures) glDeleteTextures(1, &tex);

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(g_hrc);
    ReleaseDC(g_hwnd, g_hdc);
    DestroyWindow(g_hwnd);
    return 0;
}
