#ifndef __WORLD_H__
#define __WORLD_H__

#include "bodies/body.h"
#include "bodies/chell/chell.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include <cstdint>
#include <vector>

#define GRAVITY b2Vec2(0.0, -9.8)

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::vector<Body *> bodies;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;

public:
    /* Instancia un world */
    World();

    /* Instancia un world core sobre b2world. */
    World(b2World *b2world);

    /* Libera los recursos utilizados. */
    ~World();

    /* Crea y devuelve un puntero a una Chell creada en la posicion (x, y) */
    Chell *createChell(float x, float y);

private:
    /* Libera los bodies creados */
    void deleteBodies();

    /* Libera a b2world si fue creado internamente */
    void deleteB2WorldIfInternal();
};

#endif
