#ifndef __MS_STOPWATCH_H__
#define __MS_STOPWATCH_H__
#include <Arduino.h>

class MsStopWatch {
    private:
        uint32_t _ms;
        bool _state;
        uint32_t _getElapsedTime();
    public:
        MsStopWatch();
        virtual ~MsStopWatch();
        void start();
        uint32_t stop();
        uint32_t lap();
};
#endif