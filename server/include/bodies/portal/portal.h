#ifndef __PORTAL_H__
#define __PORTAL_H__

#define PI (4*atan(1))
#define NPORTAL1 1
#define NPORTAL2 2

#include "../body.h"

class World;
class Bullet;

class Portal: public Body {
private:
    const b2Vec2 normal;
    Portal *opposite;
    const float WIDTH = 2.20;
    const float HEIGHT = 0.30;

public:
    /* Instancia un portal de numero 'portal_number' en world en la posicion
     * pos con normal 'normal' */
    Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal);

    /* Libera los recursos utilizados */
    ~Portal();

    /* Teletransporta a body al portal */
    void teleportBody(Body *body) const;

    /* Teletransporta a body al portal opuesto en caso de no ser nullptr. */
    void teleportToOppositePortal(Body *body) const;

    /* Asigna un portal opuesto */
    void setOppositePortal(Portal *opposite);

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
