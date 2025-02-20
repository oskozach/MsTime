#include "TaskTimer.h"

TaskTimer::TaskTimer() : Timer(), _exec(nullptr), _onStart(nullptr), _onStop(nullptr) {}

TaskTimer::TaskTimer(uint32_t timeout, void (*exec)(), void (*onStart)(), void (*onStop)(), uint32_t numRepeats) 
                        : Timer(timeout, numRepeats), _exec(exec), _onStart(onStart), _onStop(onStop) {}

TaskTimer::~TaskTimer() {
    if(Timer::state)
        shutDown();
}

void TaskTimer::attachExec(void (*cb)()) { _exec = cb; }
void TaskTimer::attachOnStart(void (*cb)()) { _onStart = cb; }
void TaskTimer::attachOnStop(void (*cb)()) { _onStop = cb; }

void TaskTimer::detachExec() { _exec = nullptr; }
void TaskTimer::detachOnStart() { _onStart = nullptr; }
void TaskTimer::detachOnStop() { _onStop = nullptr; }
void TaskTimer::detachAll() {
    _exec = nullptr;
    _onStart = nullptr;
    _onStop = nullptr;
}

void TaskTimer::shutDown() {
    stop();
    Timer::setTimeout(0);
    Timer::setNumRepeats(0);
    detachAll();
}

void TaskTimer::start() {
    if(Timer::state || !_exec)
        return;
    if(_onStart)
        _onStart();
    Timer::begin();
}

void TaskTimer::stop() {
    if(!(Timer::state))
        return;
    if(_onStop)
        _onStop();
    Timer::reset();
}

bool TaskTimer::tick() {
    if(!(Timer::tick()))
        return false;
    if(_exec) 
        _exec();
    if(!(Timer::state) && _onStop)
        _onStop();
    return true;
}
