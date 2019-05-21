#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../include/player.h"

#define PORT "4545"

class Accepter: public Thread {
private:
    bool keep_running;
    Socket socket;

public:
    /* Instancia un aceptador */
    Accepter();

    /* Ejecuta al aceptador */
    virtual void run() override;

    /* Detiene la ejecucion del aceptador */
    void stop();
};

#endif
