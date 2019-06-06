#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../../../server/include/boolean_suppliers/boolean_supplier.h"

class Gate;

class Button: public Body, public BooleanSupplier {
public:
    const ENTITY entity = ENTITY::BUTTON;
    bool is_pressed;
    Gate *gate;

public:
    /* Ubica un boton de id 'body_id' en b2world en la posicion (x, y) */
    Button(uint32_t body_id, b2World *b2world, float x, float y);

    /* Indica si el boton esta presionado */
    bool isPressed() const;

    /* Presiona el boton */
    void press();

    /* Suelta el boton */
    void release();

    virtual void fillIdClass(
        Update &update,
        const UpdateFactory *update_factory) const;

    virtual void handleBeginContactWith(Body *other_body) override;

    virtual void letBeginContactBeHandledBy(Chell *chell) override;

    virtual void letBeginContactBeHandledBy(Block *block) override;

    virtual void letBeginContactBeHandledBy(Button *button) override;

    virtual void letBeginContactBeHandledBy(Gate *gate) override;

    virtual void letBeginContactBeHandledBy(Rock *rock) override;

    void notifyStatusChangeTo(Gate *gate);

    /* Indica si el boton esta presionado */
    virtual bool getAsBoolean() const;
};

#endif
