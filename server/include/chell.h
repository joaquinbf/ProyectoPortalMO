#ifndef __CHELL_H__
#define __CHELL_H__

#include "../include/body.h"
#include "../include/chell_state.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"

class Chell: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 1;
    const float HALF_HEIGHT = 1;
    const float DENSITY = 1;
    const float ANGLE = 0;
    ChellState *state;

public:
    Chell(b2World *b2world, float x, float y);
    void walkLeft();
    void walkRight();
    void jump();
};

#endif
