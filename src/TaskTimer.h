#ifndef __TASK_TIMER_H__
#define __TASK_TIMER_H__
#include "Timer.h"

class TaskTimer : public Timer {
    protected:
        void (*_exec)();
        void (*_onStart)();
        void (*_onStop)();
    public:
        TaskTimer();
        TaskTimer(uint32_t timeout, void (*exec)(), 
                    void (*onStart)() = nullptr,
                    void (*onStop)() = nullptr,
                    uint32_t numRepeats = 0);
        virtual ~TaskTimer();
        void attachExec(void (*cb)());
        void attachOnStart(void (*cb)());
        void attachOnStop(void (*cb)());
        void detachExec();
        void detachOnStart();
        void detachOnStop();
        void detachAll();
        void shutDown();
        void start() override;
        void stop() override;
        bool tick() override;
};
#endif
    