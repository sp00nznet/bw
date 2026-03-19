// Black & White L3D Mesh Viewer
// Win32 + OpenGL 2.1 viewer for Lionhead .L3D mesh files
//
// Usage: bw_viewer.exe <path_to_l3d_file>
//
// Controls:
//   Left mouse drag  — orbit camera
//   Right mouse drag — zoom
//   W/A/S/D          — pan camera
//   R                — reset camera
//   Tab              — toggle wireframe
//   Escape           — quit

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <cmath>
#include <cstdio>
#include <string>

#include "l3d_loader.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

// ============================================================================
// Globals
// ============================================================================

static bw::L3DModel g_model;
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

    float light_pos[]  = { 1.0f, 2.0f, 1.5f, 0.0f };
    float light_amb[]  = { 0.2f, 0.2f, 0.2f, 1.0f };
    float light_diff[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diff);
}

static void RenderModel(const bw::L3DModel& model) {
    // Cycle colors per primitive group for visibility
    static const float colors[][3] = {
        {0.8f, 0.6f, 0.4f}, {0.4f, 0.7f, 0.8f}, {0.7f, 0.8f, 0.4f},
        {0.8f, 0.4f, 0.6f}, {0.6f, 0.4f, 0.8f}, {0.4f, 0.8f, 0.6f},
    };
    int color_idx = 0;

    for (const auto& sub : model.submeshes) {
        for (const auto& prim : sub.primitives) {
            // Use material color if available, otherwise cycle
            if (prim.color != 0) {
                float r = ((prim.color >> 16) & 0xFF) / 255.0f;
                float g = ((prim.color >>  8) & 0xFF) / 255.0f;
                float b = ((prim.color >>  0) & 0xFF) / 255.0f;
                glColor3f(r, g, b);
            } else {
                const float* c = colors[color_idx % 6];
                glColor3f(c[0], c[1], c[2]);
            }
            color_idx++;

            glBegin(GL_TRIANGLES);
            for (const auto& tri : prim.triangles) {
                for (int k = 0; k < 3; ++k) {
                    uint16_t idx = (&tri.i0)[k];
                    if (idx >= prim.vertices.size()) continue;
                    const auto& v = prim.vertices[idx];
                    glNormal3f(v.nx, v.ny, v.nz);
                    glVertex3f(v.px, v.py, v.pz);
                }
            }
            glEnd();
        }
    }
}

static void RenderGrid(float extent) {
    glDisable(GL_LIGHTING);
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
    // Axes
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(extent*0.3f,0,0); // X = red
    glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,extent*0.3f,0); // Y = green
    glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,extent*0.3f); // Z = blue
    glEnd();
    glLineWidth(1.0f);
    glEnable(GL_LIGHTING);
}

static void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = static_cast<float>(g_width) / static_cast<float>(g_height);
    gluPerspective(45.0, aspect, 0.01 * g_cam_dist, 100.0 * g_cam_dist);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Orbit camera
    float rad_yaw   = g_cam_yaw   * 3.14159265f / 180.0f;
    float rad_pitch  = g_cam_pitch * 3.14159265f / 180.0f;
    float eye_x = g_cam_x + g_cam_dist * cosf(rad_pitch) * sinf(rad_yaw);
    float eye_y = g_cam_y + g_cam_dist * sinf(rad_pitch);
    float eye_z = g_cam_z + g_cam_dist * cosf(rad_pitch) * cosf(rad_yaw);
    gluLookAt(eye_x, eye_y, eye_z, g_cam_x, g_cam_y, g_cam_z, 0.0, 1.0, 0.0);

    // Update light position in eye space
    float light_pos[] = { eye_x + 1.0f, eye_y + 2.0f, eye_z + 1.5f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    float extent = g_model.GetExtent();
    if (extent < 1.0f) extent = 1.0f;

    RenderGrid(extent);

    if (g_wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    RenderModel(g_model);

    if (g_wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

// ============================================================================
// Win32 window
// ============================================================================

static HGLRC g_hrc = nullptr;
static HDC   g_hdc = nullptr;

static bool SetupPixelFormat(HDC hdc) {
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize        = sizeof(pfd);
    pfd.nVersion     = 1;
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.iLayerType   = PFD_MAIN_PLANE;
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
        g_last_mx = LOWORD(lp);
        g_last_my = HIWORD(lp);
        SetCapture(hwnd);
        return 0;

    case WM_RBUTTONDOWN:
        g_zooming = true;
        g_last_my = HIWORD(lp);
        SetCapture(hwnd);
        return 0;

    case WM_LBUTTONUP:
        g_dragging = false;
        ReleaseCapture();
        return 0;

    case WM_RBUTTONUP:
        g_zooming = false;
        ReleaseCapture();
        return 0;

    case WM_MOUSEMOVE:
        if (g_dragging) {
            int mx = LOWORD(lp), my = HIWORD(lp);
            g_cam_yaw   += (mx - g_last_mx) * 0.5f;
            g_cam_pitch += (my - g_last_my) * 0.5f;
            if (g_cam_pitch >  89.0f) g_cam_pitch =  89.0f;
            if (g_cam_pitch < -89.0f) g_cam_pitch = -89.0f;
            g_last_mx = mx;
            g_last_my = my;
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
        case 'R':
            g_cam_yaw = 30.0f; g_cam_pitch = 20.0f;
            g_cam_dist = g_model.GetExtent() * 2.0f;
            g_cam_x = (g_model.min_x + g_model.max_x) * 0.5f;
            g_cam_y = (g_model.min_y + g_model.max_y) * 0.5f;
            g_cam_z = (g_model.min_z + g_model.max_z) * 0.5f;
            break;
        case 'W': g_cam_z -= g_cam_dist * 0.05f; break;
        case 'S': g_cam_z += g_cam_dist * 0.05f; break;
        case 'A': g_cam_x -= g_cam_dist * 0.05f; break;
        case 'D': g_cam_x += g_cam_dist * 0.05f; break;
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
    if (argc < 2) {
        fprintf(stderr, "Usage: bw_viewer.exe <path_to_l3d_file>\n");
        fprintf(stderr, "Example: bw_viewer.exe game_data/A_horse_boned.l3d\n");
        return 1;
    }

    // Load the L3D model
    if (!bw::LoadL3D(argv[1], g_model)) {
        fprintf(stderr, "Failed to load L3D file: %s\n", argv[1]);
        return 1;
    }

    // Set initial camera based on model bounds
    g_cam_x = (g_model.min_x + g_model.max_x) * 0.5f;
    g_cam_y = (g_model.min_y + g_model.max_y) * 0.5f;
    g_cam_z = (g_model.min_z + g_model.max_z) * 0.5f;
    g_cam_dist = g_model.GetExtent() * 2.0f;
    if (g_cam_dist < 1.0f) g_cam_dist = 1.0f;

    // Create window
    WNDCLASSA wc = {};
    wc.style         = CS_OWNDC;
    wc.lpfnWndProc   = WndProc;
    wc.hInstance      = GetModuleHandleA(nullptr);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName  = "BWViewer";
    RegisterClassA(&wc);

    // Build title
    char title[256];
    snprintf(title, sizeof(title), "B&W Viewer — %s (%zu submeshes, %u verts)",
             argv[1], g_model.submeshes.size(), g_model.TotalVertices());

    HWND hwnd = CreateWindowA("BWViewer", title,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, g_width, g_height,
        nullptr, nullptr, wc.hInstance, nullptr);

    if (!hwnd) {
        fprintf(stderr, "Failed to create window\n");
        return 1;
    }

    // Setup OpenGL context
    g_hdc = GetDC(hwnd);
    if (!SetupPixelFormat(g_hdc)) {
        fprintf(stderr, "Failed to set pixel format\n");
        return 1;
    }
    g_hrc = wglCreateContext(g_hdc);
    wglMakeCurrent(g_hdc, g_hrc);

    SetupGL();
    glViewport(0, 0, g_width, g_height);

    printf("Viewer ready. Controls: LMB=orbit, RMB=zoom, WASD=pan, Tab=wireframe, R=reset, Esc=quit\n");

    // Main loop
    MSG msg;
    bool running = true;
    while (running) {
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (!running) break;

        Display();
        SwapBuffers(g_hdc);
        Sleep(16); // ~60 FPS
    }

    // Cleanup
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(g_hrc);
    ReleaseDC(hwnd, g_hdc);
    DestroyWindow(hwnd);

    return 0;
}
