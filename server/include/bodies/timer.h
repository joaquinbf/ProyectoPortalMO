#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;

public:
    void start();
    double elapsedTimeInMiliSeconds();
};

#endif
