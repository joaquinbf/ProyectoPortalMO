#ifndef __PORTAL_H__
#define __PORTAL_H__

#define PI (4*atan(1))

#include "../body.h"

class World;
class Bullet;

class Portal: public Body {
private:
    const b2Vec2 normal;
    const float WIDTH = 2.20;
    const float HEIGHT = 0.30;

public:
    /* Instancia un portal de numero 'portal_number' en world en la posicion
     * pos con normal 'normal' */
    Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact);

    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) override;
};

#endif
