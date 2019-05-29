#ifndef __MATCH_H__
#define __MATCH_H__

#include "world.h"
#include "command/command.h"
#include "./chell/chell.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protected_queue.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include <cstdint>
#include <vector>

#define GRAVITY b2Vec2(0.0, -9.8)

class Match: public Thread {
private:
    bool keep_running;
    b2World b2world;
    World world;

public:
    /* Instancia una partida */
    Match();

    /* Corre la partida */
    virtual void run() override;

    /* Detiene la partida */
    void stop();

    /* Instancia una chell en el mundo que no debe ser liberada por el
     * usuario */
    Chell *createChell();

    /* Devuelve un puntero a la cola de commands */
    ProtectedQueue<Command *> *getCommandQueue();

    /* Devuelve un puntero a la cola de updates */
    ProtectedQueue<Update> *getUpdateQueue();
};

#endif
