#ifndef __MS_TIMER_H__
#define __MS_TIMER_H__
#include <Arduino.h>

class MsTimer {
    private:
        uint32_t _timeout;
        uint32_t _numRepeats;
        uint32_t _ms;
        uint32_t _cnt;
        bool _state;
    public:
        MsTimer();
        MsTimer(uint32_t timeout, uint32_t numRepeats = 0);
        virtual ~MsTimer();
        void begin();
        void reset();
        virtual void start();
        virtual void stop();
        virtual bool tick();
        void setTimeout(uint32_t timeout);
        void setNumRepeats(uint32_t num);
};
#endif
