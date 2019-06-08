#ifndef __ACID_H__
#define __ACID_H__

#include <cstdint>
#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

class World;

class Acid: public Body {
public:
    /* Instancia una mancha de acido en b2world con id 'body_id' en la
     * posicion (x, y) */
    Acid(uint32_t body_id, World *world,  float x, float y);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body);
};

#endif
