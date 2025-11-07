#pragma once

#include "../WindowManager/WindowManager.hpp"
#include <memory>

namespace Catharsis { 
    class Core {
        public:
            Core();
            void run();
            void stop(); 
        private:
            std::shared_ptr<GUI::WindowManager> m_windowManager;
    };

} // namespace Catharsis
