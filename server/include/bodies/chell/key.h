#ifndef __KEY_H__
#define __KEY_H__

#include "../../../../common/include/timer.h"

class Key {
private:
    bool pressed;
    Timer timer;

public:
    /* Instancia una tecla */
    Key();

    /* Presiona una tecla */
    void press();

    /* Suelta una tecla */
    void release();

    /* Devuelve el tiempo que lleva presionada la tecla */
    double elapsedTimeBeingPressed();
};

#endif
