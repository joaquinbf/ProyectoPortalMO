#ifndef __CHELL_H__
#define __CHELL_H__

#include "../body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include <cstdint>

class Chell: public Body {
private:
    const float HALF_WIDTH = 52;
    const float HALF_HEIGHT = 108;
    const float DENSITY = 0.001;
    const float ANGLE = 0;
    
public:
    Chell(uint32_t body_id, b2World *b2world, float x, float y);
};

#endif
