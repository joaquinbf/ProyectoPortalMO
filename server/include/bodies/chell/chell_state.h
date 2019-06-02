#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

#include "../../../../common/include/timer.h"
#include "../../../../common/include/types.h"

class Chell;

class ChellState {
protected:
    Chell *chell;
    STATUS status;
    Timer timer;

public:
    /* Instancia un estado para chell */
    ChellState(Chell *chell, STATUS status);

    /* Devuelve el estado */
    STATUS getStatus() const;

    /* Realiza una accion basada en la tecla izquierda */
    virtual void pressLeft() = 0;

    /* Realiza una accion basada en la tecla derecha */
    virtual void releaseLeft() = 0;

    /* Realiza una accion basada en la tecla derecha */
    virtual void pressRight() = 0;

    /* Realiza una accion tras soltar la tecla derecha */
    virtual void releaseRight() = 0;

    /* Aplica una accion sobre chell */
    virtual void applyStateAction();
};

#endif
