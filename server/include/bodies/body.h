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
    virtual void letBeginContactBeHandledBy(Chell *chell) = 0;

    virtual void letBeginContactBeHandledBy(Block *block) = 0;

    virtual void letBeginContactBeHandledBy(Button *button) = 0;

    virtual void letBeginContactBeHandledBy(Gate *gate) = 0;

    virtual void letBeginContactBeHandledBy(Rock *rock) = 0;

    /* Indica si el cuerpo esta despierto */
    bool isAwake() const;
};

#endif
