#pragma once

#include <vector>
#include "Events.hpp"

namespace Catharsis {
namespace Events {

    class EventManager {
            public:
                void registerEvent(const Event& event);
                void triggerEvent(const Event& event);

            private:
                std::vector<Event> eventQueue;
    };
} // namespace Events
} // namespace Catharsis
