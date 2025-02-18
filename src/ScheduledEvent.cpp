#include "ScheduledEvent.h"

ScheduledEvent::ScheduledEvent() : Timer(), _exec(nullptr), _onInit(nullptr), _onStop(nullptr) {}

ScheduledEvent::ScheduledEvent(uint32_t timeout, void (*exec)(), void (*onInit)(), void (*onStop)(), uint32_t numRepeats) 
                                : Timer(timeout, numRepeats), _exec(exec), _onInit(onInit), _onStop(onStop) {}

ScheduledEvent::~ScheduledEvent() {
    if(Timer::state)
        shutDown();
}

void ScheduledEvent::attach(const char *title, void (*cb)()) {
    if(strcmp(title, "init") == 0) {
        _onInit = *cb;
        return;
    } 
    if(strcmp(title, "stop") == 0) {
        _onStop = *cb;
    }
    if(strcmp(title, "exec") == 0) {
        _exec = *cb;
        return;
    } 
}

void ScheduledEvent::attach(void (*exec)(), void (*onInit)() = nullptr, void (*onStop)() = nullptr) {
    _exec = *exec;
    _onInit = *onInit;
    _onStop = *onStop;
}

void ScheduledEvent::detach(const char *title) {
    if(strcmp(title, "exec") == 0) {
        _exec = nullptr;
        return;
    } 
    if(strcmp(title, "init") == 0) {
        _onInit = nullptr;
        return;
    } 
    if(strcmp(title, "stop") == 0)
        _onStop = nullptr;
}

void ScheduledEvent::detachAll() {
    _exec = nullptr;
    _onInit = nullptr;
    _onStop = nullptr;
}

void ScheduledEvent::init() {
    if(_onInit)
        _onInit();
}

void ScheduledEvent::shutDown() {
    stop();
    Timer::setTimeout(0);
    Timer::setNumRepeats(0);
    detachAll();
}

void ScheduledEvent::start() {
    if(Timer::state || !_exec)
        return;
    Timer::begin();
}

void ScheduledEvent::stop() {
    if(!(Timer::state))
        return;
    Timer::reset();
    if(_onStop)
        _onStop();
}

bool ScheduledEvent::tick() {
    if(!(Timer::tick()))
        return false;
    if(_exec)
        _exec();
    if(!(Timer::state) && _onStop)
        _onStop();
    return true;
}
