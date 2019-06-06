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

class UpdateFactory;

class Body {
protected:
    const uint32_t BODY_ID;
    b2Body *b2body;

public:
    Body(uint32_t body_id);

    /* Libera los recursos utilizados */
    virtual ~Body();

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

    /* Rellena campos id. */
    void fillBodyId(Update &update) const;

    /* Rellena los campos de posicion aplicando un factor de zoom. */
    void fillPosition(
        Update &update,
        const UpdateFactory *update_factory) const;

    virtual void fillIdClass(
        Update &update,
        const UpdateFactory *update_factory) const = 0;

    virtual void fillDirection(
        Update &update,
        const UpdateFactory *update_factory) const;
};

#endif
