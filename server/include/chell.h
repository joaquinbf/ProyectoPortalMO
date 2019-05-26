#ifndef __CHELL_H__
#define __CHELL_H__

#include "../include/body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "idle_state.h"

class ChellState;

class Chell: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 1;
    const float HALF_HEIGHT = 1;
    const float DENSITY = 1;
    const float ANGLE = 0;
    ChellState *state;
    bool looking_right;

public:
    Chell(b2World *b2world, float x, float y);
    void runLeft();
    void runRight();
    void jump();
    void newState(ChellState *new_state);
};

#endif
