#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <cstdint>

class Shape;
class Material;

class Block: public Body {
private:
    Shape *shape;
    Material *material;
    const float HALF_WIDTH = 52;
    const float HALF_HEIGHT = 108;
    const float DENSITY = 0.001;
    const float ANGLE = 0;

public:
    Block(uint32_t body_id, b2World *b2world,
          float x, float y,
          Shape *shape, Material *material);
};

#endif
