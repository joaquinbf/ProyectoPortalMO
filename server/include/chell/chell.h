#ifndef __CHELL_H__
#define __CHELL_H__

#include "../body.h"


#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

#include "idle_state.h"

class ChellState;
class IdleState;

class Chell: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 5.2;
    const float HALF_HEIGHT = 10.8;
    const float DENSITY = 1;
    const float ANGLE = 0;
    ChellState *current_state;
    ChellState *old_state;
    bool is_facing_right;

public:
    Chell();

    /* Instancia a Chell en world en (x, y) */
    Chell(b2World *b2world, float x, float y);
    virtual ~Chell();
    virtual void keyLeft();
    void deleteOldStateIfUpdated();
    void setCurrentState(ChellState *state);
    void setOldState(ChellState *state);
    void updateState(ChellState *state);
    void faceLeft();
    void faceRight();
    void faceOpposite();
    void applyLinearImpulseLeft();
};

#endif
