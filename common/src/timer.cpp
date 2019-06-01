#include "../include/timer.h"

void Timer::start() {
    this->begin = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedTimeInMiliSeconds() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> miliseconds = end - this->begin;
    return miliseconds.count();
}
