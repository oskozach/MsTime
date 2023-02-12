#ifndef __MS_TIMER_H__
#define __MS_TIMER_H__
#include <stdint.h>

class MsTimer {
    private:
        uint32_t _timeout;
        uint32_t _msLastReset;
    public:
        MsTimer();
        MsTimer(uint32_t timeout);
        bool isReady();
        void setTimeout(uint32_t timeout);
        void reset();
        void restart();
};
#endif