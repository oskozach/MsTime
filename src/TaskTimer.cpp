#include "TaskTimer.h"

TaskTimer::TaskTimer() : Timer(), _exec(nullptr), _onStart(nullptr), _onReset(nullptr) {}

TaskTimer::TaskTimer(uint32_t timeout, void (*exec)(), void (*onStart)(), void (*onReset)(), uint32_t numRepeats) 
                        : Timer(timeout, numRepeats), _exec(exec), _onStart(onStart), _onReset(onReset) {}

TaskTimer::~TaskTimer() {
    if(Timer::state)
        shutDown();
}

void TaskTimer::attachExec(void (*cb)()) { _exec = cb; }
void TaskTimer::attachOnStart(void (*cb)()) { _onStart = cb; }
void TaskTimer::attachOnReset(void (*cb)()) { _onReset = cb; }

void TaskTimer::detachExec() { _exec = nullptr; }
void TaskTimer::detachOnStart() { _onStart = nullptr; }
void TaskTimer::detachOnReset() { _onReset = nullptr; }
void TaskTimer::detachAll() {
    _exec = nullptr;
    _onStart = nullptr;
    _onReset = nullptr;
}

void TaskTimer::shutDown() {
    reset();
    Timer::setTimeout(0);
    Timer::setNumRepeats(0);
    detachAll();
}

void TaskTimer::reset() {
    if(!(Timer::state))
        return;
    if(_onReset)
        _onReset();
    Timer::reset();
}

void TaskTimer::start() {
    if(Timer::state)
        return;
    if(_onStart)
        _onStart();
    Timer::start();
}

bool TaskTimer::tick() {
    if(!(Timer::tick()))
        return false;
    if(_exec) 
        _exec();
    if(!(Timer::state) && _onReset)
        _onReset();
    return true;
}
