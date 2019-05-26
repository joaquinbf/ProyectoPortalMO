#ifndef __CHELL_H__
#define __CHELL_H__

#include "../include/body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "idle_state.h"
#include "../../common/include/update.h"


class ChellState;

class Chell: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 52;
    const float HALF_HEIGHT = 108;
    const float DENSITY = 0.001;
    const float ANGLE = 0;
    ChellState *current_state;
    ChellState *old_state;

public:
    Chell(b2World *b2world, float x, float y);
    void runLeft();
    void runRight();
    void jump();
    void applyLinearImpulseToLeft();
    void applyLinearImpulseToRight();
    void applyLinearImpulseUp();
    void updateCurrentState(ChellState *new_current_state);
    void setOldState(ChellState *old_state);
    void deleteOldStateIfChanged();
    void fillUpdate(Update &update);
};

#endif
