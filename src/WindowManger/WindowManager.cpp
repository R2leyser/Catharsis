#include "WindowManager.hpp"
#include "Window.hpp"
#include "raylib.h"
#include <string>
#include <raylib-cpp.hpp>

namespace Catharsis::GUI {
    Window::Window(int width, int height, const std::string& title, int fps, bool resizable) 
        : m_width(width), m_height(height),
        m_title(title), m_isVisible(false) {
        // init the window but do not show it yet
        m_window = raylib::Window(width, height, "Catharsis Window");
        m_window.Init();
        m_window.SetTargetFPS(fps);
        m_window.SetConfigFlags( resizable ? FLAG_WINDOW_RESIZABLE : 0 | FLAG_WINDOW_UNDECORATED  | FLAG_VSYNC_HINT);

        show();
    }

    void Window::show() {
        if (!m_isVisible) {
            m_window.SetTitle(m_title);
            m_window.SetSize(m_width, m_height);
            m_isVisible = true;
            while (!m_window.ShouldClose()) {
                m_window.BeginDrawing();
                m_window.ClearBackground(RAYWHITE);
                raylib::DrawText("Welcome to Catharsis!", 190, 200, 20, LIGHTGRAY);
                m_window.EndDrawing();
            }
        }
    }

    void Window::close() {
        if (m_isVisible) {
            m_window.Close();
            m_isVisible = false;
        }
    }
}
