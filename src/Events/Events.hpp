#pragma once

#include <string>
#include <vector>
#include "EventListener.hpp"

namespace Catharsis {
namespace Events {
    class Event {
        public:
            Event(const std::string& name) : m_eventName(name) {}
            std::string getName() const { return m_eventName; }
            void addListener(const Catharsis::EventListener& listener) {
                m_listeners.push_back(listener);
            }
            void trigger();
        private:
            std::vector<Catharsis::EventListener> m_listeners;
            std::string m_eventName;
            
    };


} // namespace Events
}
