#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "../body.h"
#include "../../world.h"
#include "../../../../server/include/boolean_suppliers/boolean_supplier.h"

class Bullet;

class Receiver: public Body, public BooleanSupplier {
private:
    bool is_on;
    const float WIDHT = 2.00;
    const float HEIGHT = 2.00;

public:
    /* Instancia un receptor en world en la posicion (x, y) */
    Receiver(World *world, float x, float y);

    /* Indica si el receptor esta activado */
    bool isOn() const;

    /* Activa al receptor */
    void turnOn();

    /* Indica si el receptor esta activado */
    virtual bool getAsBoolean() const;

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body);

    /* Activa al receptor si es colisionado por una bala */
    virtual void handleBeginContactWith(Bullet *bullet);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body);
};

#endif
