#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;

public:
    /* Inicia el cronometro */
    void start();

    /* Devuelve el tiempo pasado desde el inicio en milisegundos. */
    double elapsedTimeInMiliSeconds();
};

#endif
