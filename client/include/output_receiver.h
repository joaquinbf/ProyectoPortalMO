#ifndef __OUTPUT_RECEIVER_H__
#define __OUTPUT_RECEIVER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"



// Le puse OutputReceiver para que no pisara al ya existente
// UpdateReceiver.
// Clase encargada de recibir update y nada mas, no las procesa.
// La encargada de procesar los updates debe ser otra.
class OutputReceiver: public Thread {
private:
    Protocol *protocol;
    bool keep_running;
    ProtectedQueue<Update> update_queue;

public:
    OutputReceiver(Protocol *protocol);
    virtual void run() override;
    void stop();
    Update waitAndPop();
};

#endif
