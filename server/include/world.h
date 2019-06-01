#ifndef __WORLD_H__
#define __WORLD_H__

#include "bodies/body.h"
#include "bodies/chell/chell.h"
#include "bodies/block/block.h"
#include "bodies/block/shape.h"
#include "bodies/block/square_shape.h"
#include "bodies/block/diagonal_shape.h"
#include "bodies/block/material.h"
#include "bodies/block/metal_material.h"
#include "bodies/block/stone_material.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include <cstdint>
#include <vector>
#include <list>
#include <mutex>

#define GRAVITY b2Vec2(0.0, -9.8)

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::vector<Body *> bodies;
    std::mutex mutex;
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

    /* Crea un bloque cuadrado de metal en (x, y) */
    Block *createSquareMetalBlock(float x, float y);

    /* Crea un bloque cuadrado de piedra en (x, y) */
    Block *createSquareStoneBlock(float x, float y);

    /* Devuelve una lista con los elementos del mundo para los nuevos
     * jugadores. */
    std::list<Update> getNewPlayerUpdates();

private:
    /* Libera los bodies creados */
    void deleteBodies();

    /* Libera a b2world si fue creado internamente */
    void deleteB2WorldIfInternal();
};

#endif
