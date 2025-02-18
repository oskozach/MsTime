#ifndef __SCHEDULED_EVENT_H__
#define __SCHEDULED_EVENT_H__
#include "Timer.h"

class ScheduledEvent : public Timer {
    private:
        void (*_exec)();
        void (*_onInit)();
        void (*_onStop)();
    public:
        ScheduledEvent();
        ScheduledEvent(uint32_t timeout, void (*exec)(), 
                        void (*onInit)() = nullptr,
                        void (*onStop)() = nullptr,
                        uint32_t numRepeats = 0);
        ~ScheduledEvent();
        void attach(const char *title, void (*cb)());
        void attach(void (*exec)(), void (*onInit)() = nullptr, void (*onStop)() = nullptr);
        void detach(const char *title);
        void detachAll();
        void init();
        void shutDown();
        void start() override;
        void stop() override;
        bool tick() override;
};
#endif