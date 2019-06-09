#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../common/include/types.h"
#include "../../../common/include/update.h"
#include <cstdint>

class World;

class Acid;
class Block;
class Bullet;
class Button;
class Chell;
class Gate;
class Rock;
class Launcher;
class Receiver;

class Body {
protected:
    const uint32_t BODY_ID;
    World *world;
    const ENTITY entity;
    b2Body *b2body;

public:
    Body(World *world, ENTITY entity);

    /* Libera los recursos utilizados */
    virtual ~Body();

    /* Devuelve la posicion x */
    float getPosX() const;

    /* Devuelve la posicion y */
    float getPosY() const;

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

    virtual void handleBeginContactWith(Acid *acid);

    virtual void handleBeginContactWith(Block *block);

    virtual void handleBeginContactWith(Bullet *bullet);

    virtual void handleBeginContactWith(Button *button);

    /* Deja que el inicio de contacto sea manejado por chell */
    virtual void handleBeginContactWith(Chell *chell);

    virtual void handleBeginContactWith(Gate *gate);

    virtual void handleBeginContactWith(Launcher *launcher);

    virtual void handleBeginContactWith(Receiver *receiver);

    virtual void handleBeginContactWith(Rock *rock);

    /* Maneja el fin de contacto con acid */
    virtual void handleEndContactWith(Acid *acid);

    virtual void handleEndContactWith(Block *block);

    virtual void handleEndContactWith(Bullet *bullet);

    virtual void handleEndContactWith(Button *button);

    virtual void handleEndContactWith(Chell *chell);

    virtual void handleEndContactWith(Gate *gate);

    virtual void handleEndContactWith(Launcher *launcher);

    virtual void handleEndContactWith(Receiver *receiver);

    virtual void handleEndContactWith(Rock *rock);
};

#endif
