#include "Game.hpp"

namespace Catharsis {

    Game::Game(GameSettings settings) : m_isRunning(false) {
        m_WindowManager.createWindow(
                    settings.width,
                    settings.height,
                    settings.title,
                    settings.fps,
                    settings.resizable
                );
    }

    Game::~Game() {
        m_WindowManager.closeAllWindows();
    }

    void Game::pushLayer(Layers::Layer* layer) {
        m_LayerManager.addLayer(layer);
    }

    void Game::popLayer(int index) {
        m_LayerManager.removeLayer(index);
    }

    Layers::Layer* Game::getLayer(int index) {
        return m_LayerManager.getLayer(index);
    }

    void Game::updateLayers() {
        for (auto& layer : m_LayerManager) {
            layer->onUpdate();
        }
    }

    void Game::run() {
        m_isRunning = true;
        while (m_isRunning) {
            updateLayers();
            // Additional game loop logic (rendering, event handling, etc.)
        }
    }

    void Game::stop() {
        m_isRunning = false;
    }

} // namespace Catharsis
