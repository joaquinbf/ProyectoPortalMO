#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

Launcher::Launcher(
    uint32_t body_id, World *world,
    float x, float y,
    DIRECTION direction):
    Body(body_id, world, ENTITY::LAUNCH_BLOCK),
    direction(direction),
    counter(0) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_dynamicBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDTH / 2, this->HEIGHT / 2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Update Launcher::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        0);
    return update;
}

void Launcher::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);
}

void Launcher::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}

void Launcher::applyStateAction() {
    if (this->counter > 200) {
        this->counter = 0;
        this->fireABullet();
    } else {
        this->counter += 1;
    }
}

Bullet *Launcher::fireABullet() {
    return 0;
}
