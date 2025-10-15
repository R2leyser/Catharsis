#include "Engine.hpp"
#include "../WindowManger/WindowManager.hpp"
#include <raylib-cpp.hpp>

Catharsis::Core::Core() {
    Catharsis::Core::run();
}

void Catharsis::Core::run() {
    // init rayliv
    Catharsis::GUI::Window* window = Catharsis::GUI::WindowManager::getInstance().createWindow(800, 600, "Catharsis Engine", 60, true);
              window->show();
}

void Catharsis::Core::stop() {
    Catharsis::GUI::WindowManager::getInstance().closeAllWindows();
}

