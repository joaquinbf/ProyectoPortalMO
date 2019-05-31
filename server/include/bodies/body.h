#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include <cstdint>

class Body {
protected:
    const uint32_t BODY_ID;
    b2Body *b2body;

public:
    Body(uint32_t body_id);
};

#endif
