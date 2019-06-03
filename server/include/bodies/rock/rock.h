#ifndef __ROCK_H__
#define __ROCK_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <cstdint>

class Rock: public Body {
private:
    const float HALF_WIDTH = 10;
    const float HALF_HEIGHT = 15;
    const float DENSITY = 1;
    const float ANGLE = 0;

public:
    /* Instancia una roca de id 'body_id' sobre b2orld en la
     * posicion (x, y) */
    Rock(uint32_t body_id, b2World *b2world, float x, float y);

    /* Libera los recursos utilizados */
    ~Rock();

    /* Devuelve una update de la roca */
    virtual Update createUpdate(COMMAND command) const;

    virtual void handleBeginContactWith(Body *other_body) override;

    virtual void letBeginContactBeHandledBy(Chell *chell) override;

    virtual void letBeginContactBeHandledBy(Block *block) override;

    virtual void letBeginContactBeHandledBy(Button *button) override;

    virtual void letBeginContactBeHandledBy(Gate *gate) override;

    virtual void letBeginContactBeHandledBy(Rock *rock) override;
};

#endif
