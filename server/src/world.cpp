#include "../include/world.h"

#include "../include/world_core.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

World::World():
    b2world(GRAVITY),
    world_core(&this->b2world) {
}
