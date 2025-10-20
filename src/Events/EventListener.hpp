#pragma once

namespace Catharsis {
namespace Events {
    class EventListener {
        public:
            virtual void onEvent() = 0;
    };
}}

