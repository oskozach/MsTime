#ifndef __TASK_TIMER_H__
#define __TASK_TIMER_H__
#include "Timer.h"

class TaskTimer : public Timer {
    protected:
        void (*_exec)();
        void (*_onStart)();
        void (*_onReset)();
    public:
        TaskTimer();
        TaskTimer(uint32_t timeout, 
                    void (*exec)() = nullptr, 
                    void (*onStart)() = nullptr,
                    void (*onReset)() = nullptr,
                    uint32_t numRepeats = 0);
        virtual ~TaskTimer();
        void attachExec(void (*cb)());
        void attachOnStart(void (*cb)());
        void attachOnReset(void (*cb)());
        void detachExec();
        void detachOnStart();
        void detachOnReset();
        void detachAll();
        void shutDown();
        void reset() override;
        void start() override;
        bool tick() override;
};
#endif
    