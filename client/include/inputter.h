#ifndef __INPUTTER_H__
#define __INPUTTER_H__

#include "input_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"

// Clase de prueba.
// Procesa (imprime) datos y se los pasa a InputSender para que los envie.
class Inputter: public Thread {
private:
    InputSender input_sender;

public:
    Inputter(Protocol *protocol);

    // Imprime y envia 10 actions a server.
    virtual void run() override;

    void stop();
};

#endif
