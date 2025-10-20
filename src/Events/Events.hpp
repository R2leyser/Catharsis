#pragma once

#include <string>
#include <vector>
#include "EventListener.hpp"

namespace Catharsis {
namespace Events {

    class Event {
        public:
            Event(const std::string& name) : eventName(name) {}
            std::string getName() const { return eventName; }
        private:
            std::vector<EventListener> listeners;
            std::string m_eventName;
            
    };


} // namespace Events
}
