#ifndef __CHELL_H__
#define __CHELL_H__

#include "../body.h"

#include "idle_state.h"
#include "running_state.h"

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

class ChellState;

class Chell: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 5.2;
    const float HALF_HEIGHT = 10.8;
    const float DENSITY = 1;
    const float ANGLE = 0;
    bool is_facing_right;
    ChellState *state;
    IdleState idle_state;
    RunningState running_state;

public:
    /* Instancia a Chell en world en (x, y) */
    Chell(b2World *b2world, float x, float y);
    virtual ~Chell();
    virtual void keyLeft();
    void faceLeft();
    void faceRight();
    void faceOpposite();
    void applyLinearImpulseLeft();
};

#endif
