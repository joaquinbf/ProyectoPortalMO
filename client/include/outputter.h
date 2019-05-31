#ifndef __OUTPUTTER_H__
#define __OUTPUTTER_H__

#include "output_receiver.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"

// Clase de prueba
// Recibe outputs de OutputReceiver y los procesa (imprime).
class Outputter: public Thread {
private:
    OutputReceiver output_receiver;

public:
    // Instancia un outputter estableciendo la comunicacion mediante el
    // protocolo.
    Outputter(Protocol *protocol);

    // Recibe e imprime 10 updates de server.
    virtual void run() override;

    // Detiene el thread.
    void stop();
};

#endif
