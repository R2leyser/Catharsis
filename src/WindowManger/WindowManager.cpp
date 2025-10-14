#include "WindowManager.h"
#include "Functions.hpp"
#include <raylib-cpp.hpp>

class LayerWindow {
public:
    LayerWindow(int width, int height, int fps, bool antiAliasing, 
                bool resizable, bool fullscreen, bool vsync, 
                const std::string& title) 
        : m_width(width),
        m_height(height),
        m_isVisible(false),
        m_fps(fps),
        m_antiAliasing(antiAliasing),
        m_resizable(resizable),
        m_fullscreen(fullscreen),
        m_vsync(vsync),
        m_title(title) {

        m_window = raylib::Window(width, height, title.c_str());
        m_window.SetConfigFlags((antiAliasing ? FLAG_MSAA_4X_HINT : 0) |
                                       (resizable ? FLAG_WINDOW_RESIZABLE : 0) |
                                       (fullscreen ? FLAG_FULLSCREEN_MODE : 0) |
                                       (vsync ? FLAG_VSYNC_HINT : 0));

        m_window.SetTargetFPS(fps);
    }

    void show() {
        m_isVisible = true;
        while (!m_window.ShouldClose() && m_isVisible) {
            m_window.BeginDrawing();
            m_window.ClearBackground(RAYWHITE);
            raylib::DrawText("This is a window", 10, 10, 20, DARKGRAY);
            m_window.EndDrawing();
        }
    }

    void close() {
        m_isVisible = false;
        m_window.Close();
    }
private:
    raylib::Window m_window;

    int m_width;
    int m_height;
    int m_fps;
    std::string m_title;

    bool m_isVisible;

    bool m_antiAliasing = true;
    bool m_resizable = true;
    bool m_fullscreen = false;
    bool m_vsync = true;
};
