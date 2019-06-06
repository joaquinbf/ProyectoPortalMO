#include "../../../include/bodies/gate/gate.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/rock/rock.h"


Gate::Gate(uint32_t body_id, b2World *b2world, float x, float y):
    Body(body_id){
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = b2world->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);
}

void Gate::fillIdClass(
    Update &update,
    const UpdateFactory *update_factory) const {

}

void Gate::handleBeginContactWith(Body *other_body) {
    other_body->letBeginContactBeHandledBy(this);
}

void Gate::letBeginContactBeHandledBy(Chell *chell) {
}

void Gate::letBeginContactBeHandledBy(Block *block) {
}

void Gate::letBeginContactBeHandledBy(Button *button) {
}

void Gate::letBeginContactBeHandledBy(Gate *gate) {
}

void Gate::letBeginContactBeHandledBy(Rock *gate) {
}

void Gate::notifyStateChange() {
    if (this->boolean_block->getAsBoolean()) {
        // cambiar de estado a abierta
    } else {
        // cambia de estado a cerrada
    }
}

void Gate::setBooleanBlock(BooleanBlock *boolean_block) {
    this->boolean_block = boolean_block;
}
