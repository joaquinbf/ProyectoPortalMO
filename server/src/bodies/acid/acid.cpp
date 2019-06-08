#include "../../../include/bodies/acid/acid.h"
#include "../../../include/bodies/body.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Acid::Acid(uint32_t body_id, World *world,  float x, float y):
    Body(body_id, world, ENTITY::ACID) {

}

Update Acid::createUpdate(COMMAND command) const {
    Update update;
    return update;
}

void Acid::handleBeginContactWith(Body *other_body) {

}

void Acid::handleEndContactWith(Body *other_body) {

}
