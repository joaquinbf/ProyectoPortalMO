#ifndef __PORTAL_H__
#define __PORTAL_H__

#include "../body.h"

class Portal: public Body {
private:
    const b2Vec2 pos;
    const b2Vec2 n;

public:
    /* Instancia un portal en world en pos con normal n */
    Portal(World *world, b2Vec2 pos, b2Vec2 n, uint8_t number);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact);
};

#endif
