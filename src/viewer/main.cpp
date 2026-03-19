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
#include "mesh_names.h"

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

static bw::L3DModel   g_single_model;
static bw::G3DArchive g_archive;
static bool            g_archive_mode = false;
static int             g_current_mesh = 0;
static bw::L3DModel*  g_active_model = nullptr;

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
    if (!g_active_model) return;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = static_cast<float>(g_width) / static_cast<float>(g_height);
    gluPerspective(45.0, aspect, 0.01 * g_cam_dist, 100.0 * g_cam_dist);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float rad_yaw   = g_cam_yaw   * 3.14159265f / 180.0f;
    float rad_pitch  = g_cam_pitch * 3.14159265f / 180.0f;
    float eye_x = g_cam_x + g_cam_dist * cosf(rad_pitch) * sinf(rad_yaw);
    float eye_y = g_cam_y + g_cam_dist * sinf(rad_pitch);
    float eye_z = g_cam_z + g_cam_dist * cosf(rad_pitch) * cosf(rad_yaw);
    gluLookAt(eye_x, eye_y, eye_z, g_cam_x, g_cam_y, g_cam_z, 0.0, 1.0, 0.0);

    float light_pos[] = { eye_x + 1.0f, eye_y + 2.0f, eye_z + 1.5f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    float extent = g_active_model->GetExtent();
    if (extent < 1.0f) extent = 1.0f;

    RenderGrid(extent);

    if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    RenderModel(*g_active_model);
    if (g_wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
        g_dragging = true;
        g_last_mx = LOWORD(lp); g_last_my = HIWORD(lp);
        SetCapture(hwnd);
        return 0;
    case WM_RBUTTONDOWN:
        g_zooming = true;
        g_last_my = HIWORD(lp);
        SetCapture(hwnd);
        return 0;
    case WM_LBUTTONUP:
        g_dragging = false; ReleaseCapture(); return 0;
    case WM_RBUTTONUP:
        g_zooming = false; ReleaseCapture(); return 0;

    case WM_MOUSEMOVE:
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
        case 'W': g_cam_z -= g_cam_dist * 0.05f; break;
        case 'S': g_cam_z += g_cam_dist * 0.05f; break;
        case 'A': g_cam_x -= g_cam_dist * 0.05f; break;
        case 'D': g_cam_x += g_cam_dist * 0.05f; break;
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

    if (ext == "g3d") {
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

    // Upload textures if in archive mode
    if (g_archive_mode) {
        UploadTextures(g_archive);
    }

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
