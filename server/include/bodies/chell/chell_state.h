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
    virtual void pressLeft();

    /* Realiza una accion basada en la tecla derecha */
    virtual void releaseLeft();

    /* Realiza una accion basada en la tecla derecha */
    virtual void pressRight();

    /* Realiza una accion tras soltar la tecla derecha */
    virtual void releaseRight();

    /* Realiza una accion tras presional la tecla de arriba */
    virtual void pressUp();

    /* Realiza una accion tras solatar la tecla de arriba */
    virtual void releaseUp();

    /* Aterriza a chell */
    virtual void land();

    /* Aplica una accion sobre chell */
    virtual void applyStateAction();

    /* Inicia el contador del cronometro */
    void startTimer();
};

#endif
