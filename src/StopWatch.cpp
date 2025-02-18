#include "StopWatch.h"

StopWatch::StopWatch() : _ms(0), _state(false) {}

StopWatch::~StopWatch() {}

uint32_t StopWatch::_getElapsedTime() {
    return (millis() - _ms);
}

void StopWatch::start() {
    if(_state)
        return;
    _state = true;
    _ms = millis();
}

uint32_t StopWatch::stop() {
    if(!_state)
        return 0;
    uint32_t res = _getElapsedTime();
    _ms = 0;
    _state = false;
    return res;
}

uint32_t StopWatch::lap() {
    return (_state) ? _getElapsedTime() : 0;
}
