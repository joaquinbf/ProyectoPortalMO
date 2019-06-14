#include "../../../include/bodies/portal/portal_gun.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/ray_cast_closest_body_callback.h"
#include "../../../include/world.h"

PortalGun::PortalGun(Chell *chell):
    chell(chell),
    portal_one(0),
    portal_two(0) {
}

Portal *PortalGun::getPortalOne() const {
    return this->portal_one;
}

Portal *PortalGun::getPortalTwo() const {
    return this->portal_two;
}

void PortalGun::firePortalOne(float x, float y) {
    this->firePortal(this->portal_one, x, y);
}

void PortalGun::firePortalTwo(float x, float y) {
    this->firePortal(this->portal_two, x, y);
}

void PortalGun::firePortal(Portal *portal, float x, float y) {

}
