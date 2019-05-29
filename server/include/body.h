#ifndef __BODY_H__
#define __BODY_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include <cstdint>

class Body {
private:
    uint32_t body_id;

protected:
    b2Body *b2body;

public:
    Body(uint32_t body_id);
    virtual ~Body();
    uint32_t getBodyId();
};

#endif
