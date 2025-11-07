#pragma once

#include "../Layers/Layers.hpp"
#include "../WindowManager/WindowManager.hpp"
#include "../Engine/Engine.hpp"

namespace Catharsis {
    struct GameSettings {
        std::string title = "Catharsis Application";
        int width = 800;
        int height = 600;
        int fps = 60;
        bool resizable = true;
    };

    class Game {

    public:
        Game(GameSettings settings = GameSettings());
        ~Game();

        void pushLayer(Layers::Layer* layer);
        void popLayer(int index = -1);
        Layers::Layer* getLayer(int index);

        void updateLayers();

        void run();
        void stop();
        
        GUI::WindowManager& getWindowManager() { return m_WindowManager; }
        Core& getEngine() { return m_Engine; }
        
    private:
        Layers::LayerManager m_LayerManager;
        GUI::WindowManager m_WindowManager;
        Core m_Engine;
        bool m_isRunning;

    };
} // namespace Catharsis

