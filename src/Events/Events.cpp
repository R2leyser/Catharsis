#include "Events.hpp"
#include "EventListener.hpp"

void Catharsis::Events::Event::trigger() {
    for (EventListener listener : m_listeners) {
        listener.onEvent();
    }
    return;
}
