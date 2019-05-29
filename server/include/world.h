#ifndef __WORLD_H__
#define __WORLD_H__

#include "body.h"
#include "chell/chell.h"
#include "command/command.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include <map>
#include <vector>
#include <mutex>

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    std::map<uint32_t, Chell *> chells;
    std::vector<Body *> bodies;
    std::mutex m;
    ProtectedQueue<Command *> commands_queue;
    ProtectedQueue<Update> updates_queue;

public:
    /* Instancia un world sobre b2world de Box2D */
    World(b2World *b2world);

    /* Libera los recursos utilizados */
    ~World();

    /* Crea una chell en world y devuelve su puntero.
     * Es world quien se encargara de liberar su recursos.
     * Pre: No puede ser creada durante un step de world.  */
    Chell *createChell();

    /* Devuelve un puntero a la cola de commands */
    ProtectedQueue<Command *> *getCommandsQueue();

    /* Devuelve un puntero a la cola de updates */
    ProtectedQueue<Update> *getUpdatesQueue();
};

#endif
