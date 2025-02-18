#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__
#include <Arduino.h>

class StopWatch {
    private:
        uint32_t _ms;
        bool _state;
        uint32_t _getElapsedTime();
    public:
        StopWatch();
        virtual ~StopWatch();
        void start();
        uint32_t stop();
        uint32_t lap();
};
#endif
