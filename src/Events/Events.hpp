#pragma once

#include <string>
#include <vector>

namespace Catharsis {
namespace Events {

    class Event {
        public:
            Event(const std::string& name) : eventName(name) {}
            std::string getName() const { return eventName; }
        private:
            std::string eventName;
    };

    class EventListener {
        public:
            virtual void onEvent(const Event& event) = 0;
    };

    class EventManager {
        public:
            void registerEvent(const Event& event) {
                // Implementation for registering an event
            }
            void triggerEvent(const Event& event);
            void addListener(EventListener* listener) {
                listeners.push_back(listener);
            }

        private:
            std::vector<EventListener*> listeners;
            std::vector<Event> eventQueue;
    };
} // namespace Events
}
