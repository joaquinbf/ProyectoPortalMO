#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/Contacts/b2Contact.h"
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
    virtual void handleBeginContactWith(Body *body, b2Contact *contact) = 0;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact) = 0;

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

    virtual void handleBeginContactWith(Acid *acid, b2Contact *contact);

    virtual void handleBeginContactWith(Block *block, b2Contact *contact);

    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact);

    virtual void handleBeginContactWith(Button *button, b2Contact *contact);

    /* Deja que el inicio de contacto sea manejado por chell */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact);

    virtual void handleBeginContactWith(Gate *gate, b2Contact *contact);

    virtual void handleBeginContactWith(Launcher *launcher, b2Contact *contact);

    virtual void handleBeginContactWith(Receiver *receiver, b2Contact *contact);

    virtual void handleBeginContactWith(Rock *rock, b2Contact *contact);

    /* Maneja el fin de contacto con acid */
    virtual void handleEndContactWith(Acid *acid, b2Contact *contact);

    virtual void handleEndContactWith(Block *block, b2Contact *contact);

    virtual void handleEndContactWith(Bullet *bullet, b2Contact *contact);

    virtual void handleEndContactWith(Button *button, b2Contact *contact);

    virtual void handleEndContactWith(Chell *chell, b2Contact *contact);

    virtual void handleEndContactWith(Gate *gate, b2Contact *contact);

    virtual void handleEndContactWith(Launcher *launcher, b2Contact *contact);

    virtual void handleEndContactWith(Receiver *receiver, b2Contact *contact);

    virtual void handleEndContactWith(Rock *rock, b2Contact *contact);
};

#endif
