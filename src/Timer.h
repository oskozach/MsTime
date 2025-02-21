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
    public:
        Timer();
        Timer(uint32_t timeout, uint32_t numRepeats = 0);
        virtual ~Timer();
		void refresh();
        virtual void reset();
        virtual void start();
        virtual bool tick();
        bool getState();
        void setTimeout(uint32_t timeout);
        void setNumRepeats(uint32_t num);
};
#endif
