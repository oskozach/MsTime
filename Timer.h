#ifndef __TIMER_H__
#define __TIMER_H__
#include <Arduino.h>

class Timer {
    private:
        uint32_t _timeout;
        uint32_t _numRepeats;
        uint32_t _ms;
        uint32_t _cnt;
    protected:
        bool state;
        void begin();
        void reset();
    public:
        Timer();
        Timer(uint32_t timeout, uint32_t numRepeats = 0);
        virtual ~Timer();
        virtual void start();
        virtual void stop();
        virtual bool tick();
        void setTimeout(uint32_t timeout);
        void setNumRepeats(uint32_t num);
};
#endif
