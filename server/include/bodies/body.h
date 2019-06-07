#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../common/include/types.h"
#include "../../../common/include/update.h"
#include <cstdint>

class Chell;
class Block;
class Button;
class Gate;
class Rock;

class Body {
protected:
    const uint32_t BODY_ID;
    b2Body *b2body;
    const ENTITY entity;

public:
    Body(uint32_t body_id, ENTITY entity);

    /* Libera los recursos utilizados */
    virtual ~Body();

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const = 0;

    /* Devuelve un identificador del cuerpo */
    uint32_t getBodyId() const;

    /* Aplica una accion sobre el cuerpo dependiendo de su estado */
    virtual void applyStateAction();

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body) = 0;

    /* Deja que el inicio de contacto sea manejado por chell */
    virtual void handleBeginContactBeHandledBy(Chell *chell);

    virtual void handleBeginContactBeHandledBy(Block *block);

    virtual void handleBeginContactBeHandledBy(Button *button);

    virtual void handleBeginContactBeHandledBy(Gate *gate);

    virtual void handleBeginContactBeHandledBy(Rock *rock);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body) = 0;

    virtual void handleEndContactBeHandledBy(Chell *chell);

    virtual void handleEndContactBeHandledBy(Block *block);

    virtual void handleEndContactBeHandledBy(Button *button);

    virtual void handleEndContactBeHandledBy(Gate *gate);

    virtual void handleEndContactBeHandledBy(Rock *rock);

    /* Indica si el cuerpo esta despierto */
    bool isAwake() const;
};

#endif
