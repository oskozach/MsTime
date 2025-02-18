#include "Timer.h"

Timer::Timer() : _timeout(5), _numRepeats(0), 
                        _ms(0), _cnt(0), state(false) {}

Timer::Timer(uint32_t timeout, uint32_t numRepeats)
                    : _numRepeats(numRepeats), _ms(0), 
                        _cnt(0), state(false) { 
    setTimeout(timeout); 
}

Timer::~Timer() {}

void Timer::begin() {
    _ms = millis();
    _cnt = 0;
    state = true;
}

void Timer::reset() {
    _ms = 0;
    _cnt = 0;
    state = false;
}

void Timer::start() {
    if(state)
        return;
    begin();
}

void Timer::stop() {
    if(!state)
        return;
    reset();
}

bool Timer::tick() {
    if(!state)
        return false;
    uint32_t tm = millis();
    if(tm - _ms < _timeout)
        return false;
    if(_numRepeats > 0
            && ++_cnt >= _numRepeats) {
        reset();
        return true;
    }
    _ms = tm;
    return true;
}

void Timer::setTimeout(uint32_t timeout) {
    _timeout = (timeout == 0) ? 5 : timeout;
}

void Timer::setNumRepeats(uint32_t num) {
    _numRepeats = num;
}
