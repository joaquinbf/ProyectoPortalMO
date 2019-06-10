#include "../../../include/bodies/portal/portal.h"

Portal::Portal(World *world, b2Vec2 pos, b2Vec2 n, uint8_t number):
    Body(world, number == 1 ? ENTITY::PORTAL1 : ENTITY::PORTAL2),
    pos(pos), n(n) {

}

Update Portal::createUpdate(COMMAND command) const {
    Update update;
    return update;
}

void Portal::handleBeginContactWith(Body *body, b2Contact *contact) {

}

void Portal::handleEndContactWith(Body *body, b2Contact *contact) {

}
