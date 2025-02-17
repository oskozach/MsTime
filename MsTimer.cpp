#include "MsTimer.h"

MsTimer::MsTimer() : _timeout(0), _msLastReset(0) {}
MsTimer::MsTimer(uint32_t timeout) : _timeout(timeout), _msLastReset(0) {}
void MsTimer::restart() { _msLastReset = 0; }
void MsTimer::reset() { _msLastReset = millis(); }
void MsTimer::setTimeout(uint32_t timeout) {
    _timeout = (timeout == 0) ? 5 : timeout;
}
bool MsTimer::isReady() {
    return millis() - _msLastReset >= _timeout; 
}