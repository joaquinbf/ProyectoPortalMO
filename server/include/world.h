#ifndef __WORLD_H__
#define __WORLD_H__

#include "bodies/body.h"
#include "bodies/chell/chell.h"
#include "../include/bodies/button/button.h"
#include "bodies/block/block.h"
#include "bodies/block/shape.h"
#include "bodies/block/square_shape.h"
#include "bodies/block/diagonal_shape.h"
#include "bodies/block/material.h"
#include "bodies/block/metal_material.h"
#include "bodies/block/stone_material.h"
#include "boolean_suppliers/boolean_block_factory.h"
#include "contact_listener.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include <cstdint>
#include <vector>
#include <list>
#include <map>
#include <mutex>

#define GRAVITY b2Vec2(0.0, -9.8)
#define MAX_CHELLS 4

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::vector<Body *> bodies;
    std::map<uint32_t, Chell *> chells;
    std::mutex mutex;
    const float TIME_STEP = 1/30.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;
    BooleanBlockFactory boolean_block_factory;
    ContactListener contact_listener;

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

    /* Crea un boton. TODO: Asignar a compuertas */
    Button *createButton(float x, float y);

    /* Crea una compuerta sin estar asociada a ningun boton ni receptores
     *en (x, y) */
    Gate *createGate(float x, float y);

    /* Crea el centro de gate en (x1, y1) y un boton con su
     * centro en (x2, y2).
     * Para que la compuerta se abra si el boton esta presionado entonces
     * open_gate_when_button_is_pressed debe ser true y false en caso
     * contrario. */
    void createGateWithButton(
        float x1, float y1,
        float x2, float y2,
        bool open_gate_when_button_is_pressed);

    /* Devuelve una lista con los elementos del mundo para los nuevos
     * jugadores. */
    std::list<Update> getNewPlayerUpdates() const;

    /* Devuelve una lista con updates del mundo. */
    std::list<Update> getUpdates() const;

    /* Devuelve una lista de updates pero solo con los cuerpos despiertos */
    std::list<Update> getUpdatesForAwakeBodies() const;

    /* Actualiza el mundo en un step. */
    void step();

    /* Crea el world 01: Un mundo de 6 bloques de metal y 4 chells.  */
    void createWorldOne();

    /* Aplica una accion sobre world. */
    void applyAction(const Action &action);

    /* Aplica las acciones de estado sobre los bodies */
    void applyStateActions();

    /* Devuelve su boolean block factory */
    BooleanBlockFactory *getBooleanBlockFactory();

private:
    /* Libera los bodies creados */
    void deleteBodies();

    /* Libera a b2world si fue creado internamente */
    void deleteB2WorldIfInternal();

    /* Devuelve updates con COMMAND asignado. */
    std::list<Update> getUpdatesWithCommand(COMMAND command) const;
};

#endif
