#ifndef __ROCK_H__
#define __ROCK_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <cstdint>

class World;

class Rock: public Body {
private:
    const float WIDTH = 1.0;
    const float HEIGHT = 1.0;

public:
    /* Instancia una roca de id 'body_id' sobre b2orld en la
     * posicion (x, y) */
    Rock(World *world, float x, float y);

    /* Libera los recursos utilizados */
    ~Rock();

    /* Devuelve una update de la roca */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    /* Es tomado por chell si esta en grabbing mode */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact) override;
};

#endif
