#include "MsStopWatch.h"

MsStopWatch::MsStopWatch() : _ms(0), _state(false) {}

MsStopWatch::~MsStopWatch() {}

uint32_t MsStopWatch::_getElapsedTime() {
    return (millis() - _ms);
}

void MsStopWatch::start() {
    if(_state)
        return;
    _state = true;
    _ms = millis();
}

uint32_t MsStopWatch::stop() {
    if(!_state)
        return 0;
    uint32_t res = _getElapsedTime();
    _ms = 0;
    _state = false;
    return res;
}

uint32_t MsStopWatch::lap() {
    return (_state) ? _getElapsedTime() : 0;
}
