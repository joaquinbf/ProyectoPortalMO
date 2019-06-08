#ifndef __WORLD_H__
#define __WORLD_H__

#include "bodies/body.h"
#include "bodies/chell/chell.h"
#include "bodies/bullet/bullet.h"
#include "../include/bodies/button/button.h"
#include "pin.h"
#include "bodies/block/block.h"
#include "bodies/block/shape.h"
#include "bodies/block/square_shape.h"
#include "bodies/block/diagonal_shape.h"
#include "bodies/block/material.h"
#include "bodies/block/metal_material.h"
#include "bodies/block/stone_material.h"
#include "../include/bodies/launcher/launcher.h"
#include "boolean_suppliers/boolean_block_factory.h"
#include "bodies/acid/acid.h"
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
#include <set>

#define GRAVITY b2Vec2(0.0, -9.8)


class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::set<Body *> bodies;
    std::map<uint32_t, Chell *> chells;
    std::map<uint32_t, Pin *> pins;
    std::map<uint32_t, uint32_t> changedPins;
    std::mutex mutex;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;
    BooleanBlockFactory boolean_block_factory;
    ContactListener contact_listener;
    std::set<Body *> dead_bodies;

public:
    /* Instancia un world */
    World();

    /* Instancia un world con time_step como la cantidad de tiempo a simular
     * en cada step */
    World(float time_step);

    /* Instancia un world core sobre b2world. */
    World(b2World *b2world);

    /* Libera los recursos utilizados. */
    ~World();

    /* Devuelve la cantidad de cuerpos que han existido.*/
    uint32_t getBodyCount() const;

    /* Devuelve la cantidad de cuerpos que existen en este momento.
     * No cuenta los cuerpos que murieron. */
    uint32_t getBodySize() const;

    /* Devuelve b2world */
    b2World *getB2World();

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

    /* Crea una mancha de acido en (x, y) */
    Acid *createAcid(float x, float y);

    /* Crea un lanzador en (x, y) apuntando en la direccion ada.*/
    Launcher *createLauncher(float x, float y, DIRECTION direction);

    /* Crea una bala en (x, y) desplazandose en direction 'direction' */
    Bullet *createBullet(float x, float y, DIRECTION direction);

    /* Devuelve una lista con los elementos del mundo para los nuevos
     * jugadores. */
    std::list<Update> getNewPlayerUpdates() const;

    /* Devuelve una lista con updates del mundo. */
    std::list<Update> getUpdates() const;

    /* Devuelve una lista de updates pero solo con los cuerpos despiertos */
    std::list<Update> getUpdatesForAwakeBodies() const;
    std::list<Update> getPinUpdateList();
    void createNewPin(uint32_t id, int32_t x, int32_t y);

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
