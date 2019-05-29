#ifndef __WORLD_H__
#define __WORLD_H__

#include "body.h"
#include "chell/chell.h"
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

public:
    /* Instancia un world sobre b2world de Box2D */
    World(b2World *b2world);

    /* Libera los recursos utilizados */
    ~World();

    /* Crea una chell en world y devuelve su puntero.
     * Es world quien se encargara de liberar su recursos.
     * Pre: No puede ser creada durante un step de world.  */
    Chell *createChell();
};

#endif
