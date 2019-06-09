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

class World;
class Gate;

// Trapecio isoceles
#define b 1.00
#define B 2.00
#define h 0.50

// Centro de masa
#define Cx (B/2)
#define Cy (((B + 2*b)/(B + b))*(h/3))

#define P1 0.00, 0.00
#define P2 0.50, 0.25
#define P3 1.50, 0.25
#define P4 2.00, 0.00

#define XADJ -Cx
#define YADJ -Cy

class Button: public Body, public BooleanSupplier {
public:
    bool is_pressed;
    Gate *gate;
    const float FRICTION = 0.7;
    const float RESTITUTION = 0.0;

public:
    /* Ubica un boton en world en la posicion (x, y) */
    Button(World *world, float x, float y);

    /* Indica si el boton esta presionado */
    bool isPressed() const;

    /* Presiona el boton */
    void press();

    /* Suelta el boton */
    void release();

    virtual Update createUpdate(COMMAND command) const override;

    void setGate(Gate *gate);

    void notifyStatusChangeToGate();

    /* Indica si el boton esta presionado */
    virtual bool getAsBoolean() const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    virtual void handleEndContactWith(Chell *chell, b2Contact *contact) override;
};

#endif
