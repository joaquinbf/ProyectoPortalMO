#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../include/player.h"
#include "../include/world.h"

#define PORT "4545"

class Accepter: public Thread {
private:
    bool keep_running;
    Socket socket;
    World *world;

public:
    /* Instancia un aceptador */
    Accepter(World *world);

    /* Ejecuta al aceptador */
    virtual void run() override;

    /* Detiene la ejecucion del aceptador */
    void stop();
};

#endif
