#pragma once
#include <raylib-cpp.hpp>
#include <vector>
#include <string>

namespace Catharsis {
namespace GUI {
// ============================================================
class Window {
public:
    Window(int width, int height, const std::string& title = "Catharsis Window", int fps = 60, bool resizable = true);
    ~Window() = default;
    void show();
    void close();
private:
    raylib::Window m_window;

    std::string m_title;
    int m_fps;
    int m_width;
    int m_height;
    bool m_isVisible;
    bool m_resizable;
};

class WindowManager {
    public:
        Window* createWindow(int width, 
                int height,
                const std::string& title = "Catharsis Window",
                int fps = 60,
                bool resizable = true
                ) {
            Window* newWindow = new Window(width, height, title, fps, resizable);
            windows.push_back(newWindow);
            return newWindow;
        }

        void closeAllWindows() {
            for (Window* window : windows) {
                window->close();
                delete window;
            }
            windows.clear();
        }

        ~WindowManager() {
            closeAllWindows();
        }
    private:
        std::vector<Window*> windows;
};
// ============================================================
} // namespace GUI
} // namespace Catharsis
