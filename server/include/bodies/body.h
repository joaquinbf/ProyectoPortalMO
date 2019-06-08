#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../common/include/types.h"
#include "../../../common/include/update.h"
#include <cstdint>

class World;

class Chell;
class Block;
class Button;
class Gate;
class Rock;

class Body {
protected:
    const uint32_t BODY_ID;
    World *world;
    const ENTITY entity;
    b2Body *b2body;

public:
    Body(uint32_t body_id, World *world, ENTITY entity);

    /* Libera los recursos utilizados */
    virtual ~Body();
    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const = 0;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body) = 0;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body) = 0;

    /* Devuelve un identificador del cuerpo */
    uint32_t getBodyId() const;

    /* Indica si el cuerpo esta despierto */
    bool isAwake() const;

    /* Despierta al cuerpo */
    void wakeUp();

    /* Duerme al cuerpo */
    void putToSleep();

    /* Devuelve la masa del cuerpo */
    float getMass() const;

    /* Aplica una accion sobre el cuerpo dependiendo de su estado */
    virtual void applyStateAction();

    /* Deja que el inicio de contacto sea manejado por chell */
    virtual void handleBeginContactWith(Chell *chell);

    virtual void handleBeginContactWith(Block *block);

    virtual void handleBeginContactWith(Button *button);

    virtual void handleBeginContactWith(Gate *gate);

    virtual void handleBeginContactWith(Rock *rock);

    virtual void handleEndContactWith(Chell *chell);

    virtual void handleEndContactWith(Block *block);

    virtual void handleEndContactWith(Button *button);

    virtual void handleEndContactWith(Gate *gate);

    virtual void handleEndContactWith(Rock *rock);
};

#endif
