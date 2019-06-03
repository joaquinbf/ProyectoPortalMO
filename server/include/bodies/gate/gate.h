#ifndef __GATE_H__
#define __GATE_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include <cstdint>

class Gate: public Body {
private:
    const float HALF_WIDTH = 100;
    const float HALF_HEIGHT = 100;

public:
    /* Instancia una compuerta de id 'body_id' en b2world en (x, y) */
    Gate(uint32_t body_id, b2World *b2world, float x, float y);

    virtual Update createUpdate(COMMAND command) const;

    virtual void handleBeginContactWith(Body *other_body) override;

    virtual void letBeginContactBeHandledBy(Chell *chell) override;

    virtual void letBeginContactBeHandledBy(Block *block) override;

    virtual void letBeginContactBeHandledBy(Button *button) override;

    virtual void letBeginContactBeHandledBy(Gate *gate) override;
};

#endif
