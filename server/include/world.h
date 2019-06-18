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
#include "../include/instructions/instruction_factory.h"
#include <cstdint>
#include <vector>
#include <list>
#include <map>
#include <mutex>
#include <set>
#include <deque>


class Instruction;
class Chell;
class Receiver;
class Launcher;
class Rock;
class Gate;
class Button;
class Acid;
class Portal;
class Cake;
class Rock;
class Laser;

#define GRAVITY b2Vec2(0.0, -9.8)

/* Representa al mundo de juego.
 * Utiliza dos sistemas de control de memoria.
 * 1. Automatico: Se llama al destruirse world. Destruye a todos los elementos
 *                que queden en world.
 * 2. Manual: Permite destruir de manera controlada a objetos en world.
 *
 * Aquellos objetos aglomerados en los que tras eliminar uno se eliminen los
 * otros deben ser eliminados manualmente, en caso contrario el orden de
 * eliminacion no es asegurado pudiendo generar memory leaks.
 * Se recomienda destruir manualmente los bodies y solo dejar a eliminacion
 * automatica a aquellos que no sean aglomerados.
 * ejemplo: body no aglomerado(simples) = bullet, block, launcher.
 *          aglomerado: Chell, puede contener portales.*/

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::set<Body *> bodies;
    std::map<uint32_t, Chell *> chells;
    std::map<uint32_t, Pin *> pins;
    std::map<uint32_t, uint32_t> changedPins;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;
    BooleanBlockFactory boolean_block_factory;
    ContactListener contact_listener;
    std::set<Body *> bodies_for_deletion;
    std::deque<Instruction *> instructions;
    std::deque<Update>  internal_updates;
    InstructionFactory instruction_factory;
    Cake *cake;

public:
    /* Instancia un world */
    World();

    /* Instancia un world con time_step como la cantidad de tiempo a simular
     * en cada step */
    World(float time_step);

    /* Instancia un world core sobre b2world. */
    World(b2World *b2world);

    /* No se permite construccion por movimiento */
    World(World &&world) = delete;

    /* No se permite la construccion por copia */
    World(const World &world) = delete;

    /* No se permite asignacion por movimiento */
    World &operator=(World &&other) = delete;

    /* No se permite la asignacion por copia */
    World &operator=(const World &other) = delete;

    /* Libera los recursos utilizados. */
    ~World();

    /* Elimina a chell del conjunto de chells */
    void removeFromChells(Chell *chell);

    /* Indica si todos los jugadores comieron del pastel */
    bool everybodyAteTheCake() const;

    /* Indica si todos los jugadores menos uno comieron del pastel */
    bool everybodyButOneAteTheCake() const;

    /* Incrementa el contador de bodies */
    void incBodyCount();

    /* Agrega un nuevo body al set bodies */
    void addToBodies(Body *body);

    /* Agrega una update a la coleccion de updates*/
    void addUpdate(Update update);

    /* Elimina a body de world */
    void destroyBody(Body *body);

    /* Agrega una instruccion a la cola de instrucciones */
    void addInstruction(Instruction *instruction);

    /* Aplica inputs externos sobre world. */
    void addExternalInput(ProtectedQueue<Action> *inputs);

    /* Aplica instrucciones, simula un step de world y genera updates. */
    void bigStep();

    /* Aplica instrucciones sobre world */
    void applyInstructions();

    /* Crea updates */
    void createUpdates();

    /* Rellana ext_updates con updates*/
    void fillUpdates(ProtectedQueue<Update> *ext_updates);

    /* Agrega un nuevo body a world */
    void insertNewBody(Body *body);

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

    /* Crea un bloque diagonal metalico en (x, y) del tipo 'orientation' */
    Block *createDiagonalMetalBlock(float x, float y, ORIENTATION orientation);

    /* Crea un boton. */
    Button *createButton(float x, float y);

    /* Crea una compuerta sin estar asociada a ningun boton ni receptores
     *en (x, y) */
    Gate *createGate(float x, float y);

    /* Crea una compuerta sin estar asociada a ningun boton ni receptores
     *en (x, y) */
    Gate *createRegularGate(float x, float y);

    /* Crea una compuerta del tipo AND en (x, y) */
    Gate *createAndGate(float x, float y);

    /* Crea una compuerta del tipo OR en (x, y) */
    Gate *createOrGate(float x, float y);

    /* Crea una mancha de acido en (x, y) */
    Acid *createAcid(float x, float y);

    /* Crea un lanzador en (x, y) apuntando en la direccion ada.*/
    Launcher *createLauncher(float x, float y, DIRECTION direction);

    /* Crea una bala en (x, y) desplazandose en direction 'direction' */
    Bullet *createBullet(float x, float y, DIRECTION direction);

    /* Crea un receptor en (x, y) */
    Receiver *createReceiver(float x, float y);

    /* Crea un portal de numbe 'portal_number' en pos con normal 'normal'. */
    Portal *createPortal(uint8_t portal_number, b2Vec2 pos, b2Vec2 normal);

    /* Crea una pastel en la posicion(x, y).
     * Pre: Solo se puede crear un unico pastel, en caso contrario
     * devuelve nullptr.  */
    Cake *createCake(float x, float y);

    /* Crea una roca en la posicion (x, y) */
    Rock *createRock(float x, float y);

    /* Crea un laser (barrera de energia) en (x, y) con un cierto angulo.
     * Pre: Los unicos angulos permitidos son ANGLE_000 y ANGLE_090 */
    Laser *createLaser(float x, float y, ANGLE angle);

    /* Devuelve una lista con los elementos del mundo para los nuevos
     * jugadores. */
    std::list<Update> getNewPlayerUpdates() const;

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

    /* Agrega un body para ser eliminado */
    void addBodyForDeletion(Body *body);

    /* Elimina los body para ser eliminado */
    void deleteBodiesForDeletion();

    std::list<uint32_t> getChellsIdList() const;
private:
    /* Libera los bodies creados */
    void deleteAllBodies();

    /* Libera a b2world si fue creado internamente */
    void deleteB2WorldIfInternal();

    /* Devuelve updates con COMMAND asignado. */
    std::list<Update> getUpdatesWithCommand(COMMAND command) const;

    void addAllBodiesToUpdates(std::list<Update> &updates);
    void addDeletedBodiesToUpdates(std::list<Update> &updates);
};

#endif
