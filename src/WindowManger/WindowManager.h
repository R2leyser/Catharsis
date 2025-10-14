#pragma once
#include <vector>

class Window {
public:
    Window(int width, int height);
    void show();
    void close();
private:
    int width;
    int height;
    bool isVisible;
};

class WindowManager {
    public:
        static WindowManager& getInstance() {
            static WindowManager instance;
            return instance;
        }

        Window* createWindow(int width, int height) {
            Window* newWindow = new Window(width, height);
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
    private:
        WindowManager() {}
        ~WindowManager() {
            closeAllWindows();
        }
        WindowManager(const WindowManager&) = delete;
        WindowManager& operator=(const WindowManager&) = delete;
        
        std::vector<Window*> windows;
};
