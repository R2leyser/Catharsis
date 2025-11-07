#include "Engine.hpp"
#include "../WindowManager/WindowManager.hpp"
#include <raylib-cpp.hpp>
#include <memory>

Catharsis::Core::Core() {
    m_windowManager = std::make_shared<Catharsis::GUI::WindowManager>();
    Catharsis::Core::run();
}

void Catharsis::Core::run() {
    // init rayliv
    Catharsis::GUI::Window* window = m_windowManager->createWindow(800, 600, "Catharsis Engine", 60, true);
              window->show();
}

void Catharsis::Core::stop() {
    m_windowManager->closeAllWindows();
}

