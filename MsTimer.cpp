#include "MsTimer.h"

MsTimer::MsTimer() : _timeout(5), _numRepeats(0), 
                        _ms(0), _cnt(0), _state(false) {}

MsTimer::MsTimer(uint32_t timeout, uint32_t numRepeats)
                    : _numRepeats(numRepeats), _ms(0), 
                        _cnt(0), _state(false) { 
    setTimeout(timeout); 
}

MsTimer::~MsTimer() {}

void MsTimer::begin() {
    _ms = millis();
    _cnt = 0;
    _state = true;
}

void MsTimer::reset() {
    _ms = 0;
    _cnt = 0;
    _state = false;
}

void MsTimer::start() {
    if(_state)
        return;
    begin();
}

void MsTimer::stop() {
    if(!_state)
        return;
    reset();
}

bool MsTimer::tick() {
    if(!_state)
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

void MsTimer::setTimeout(uint32_t timeout) {
    _timeout = (timeout == 0) ? 5 : timeout;
}

void MsTimer::setNumRepeats(uint32_t num) {
    _numRepeats = num;
}
