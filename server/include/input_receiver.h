#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include <iostream>

/* Clase encargada de recibir el input del cliente */
class InputReceiver: public Thread {
private:
    bool keep_running;
    Protocol *protocol;
    ProtectedQueue<Action> queue;

public:
    /* Instancia un input receiver */
    InputReceiver(Protocol *protocol);

    /* Ejecuta el input recv */
    virtual void run() override;

    /* Detiene al input recv */
    void stop();

    /* Devuelve un puntero a la cola */
    ProtectedQueue<Action> *getQueue();
};

#endif
