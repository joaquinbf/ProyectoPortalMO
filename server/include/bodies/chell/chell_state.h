#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

#include "../../../../common/include/timer.h"

class Chell;

class ChellState {
protected:
    Chell *chell;
    Timer timer;

public:
    /* Instancia un estado para chell */
    ChellState(Chell *chell);

    /* Realiza una accion basada en la tecla izquierda */
    virtual void pressLeft() = 0;

    /* Realiza una accion basada en la tecla derecha */
    virtual void releaseLeft() = 0;

    /* Realiza una accion basada en la tecla derecha */
    virtual void pressRight() = 0;

    /* Realiza una accion tras soltar la tecla derecha */
    virtual void releaseRight() = 0;

    /* Cambia de estado basado en el tiempo que lleva en el mismo */
    virtual void updateStateOnTimer() = 0;
};

#endif
