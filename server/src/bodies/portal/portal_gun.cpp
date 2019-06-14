#include "../../../include/bodies/portal/portal_gun.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/ray_cast_closest_body_callback.h"
#include "../../../include/world.h"

PortalGun::PortalGun(Chell *chell):
    chell(chell),
    portal_one(nullptr),
    portal_two(nullptr) {
}

PortalGun::~PortalGun() {
    this->destroyPortal(portal_one);
    this->destroyPortal(portal_two);
}

Portal *PortalGun::getPortalOne() const {
    return this->portal_one;
}

Portal *PortalGun::getPortalTwo() const {
    return this->portal_two;
}

void PortalGun::firePortalOne(float x, float y) {
    this->destroyPortal(this->portal_one);
    this->portal_one = this->firePortal(NPORTAL1, b2Vec2(x, y));
}

void PortalGun::firePortalTwo(float x, float y) {
    this->destroyPortal(this->portal_two);
    this->portal_two = this->firePortal(NPORTAL2, b2Vec2(x, y));
}

void PortalGun::destroyPortal(Portal *portal) {
    if (portal != nullptr) {
        chell->getWorld()->destroyBody(portal);
    }
}

Portal *PortalGun::firePortal(uint8_t portal_number, b2Vec2 pos) {
    RayCastClosestBodyCallback callback;
    World *world = chell->getWorld();
    Portal *portal = nullptr;

    world->getB2World()->RayCast(
        &callback,
        chell->getPosition(),
        pos);

    if (callback.hasHit()) {
        portal = world->createPortal(
            portal_number,
            callback.getNormal(),
            callback.getNormal());
    }

    return portal;
}
