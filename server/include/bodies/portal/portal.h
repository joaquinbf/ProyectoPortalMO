#ifndef __PORTAL_H__
#define __PORTAL_H__

#include "../body.h"

class World;
class Bullet;

class Portal: public Body {
private:
    const b2Vec2 pos;
    const b2Vec2 n;
    bool is_on;
    b2Vec2 normal;
    Portal *opposite;

public:
    /* Crea un portal desactivado con number 'number */
    Portal(World *world, uint8_t number);

    /* Transporta el cuerpo al portal opuesto */
    void transportToOppositePortal(Body *body) const;

    /* Transporta al cuerpo a las cercanias del portal */
    void transportBody(Body *body) const;

    /* Crea una dupla con otro portal.
     * Pre: No tenia previamente otro portal. */
    void setPairWith(Portal *portal);

    /* Setea el vector normal */
    void setNormal(b2Vec2 normal);

    /* Indica si el portal esta activado */
    bool isOn() const;

    /* Activa el portal */
    void turnOn();

    /* Desactiva el portañ */
    void turnOff();

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact);

    /* Teletransporta a la bala al otro portal */
    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact);
};

#endif
