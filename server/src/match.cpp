#include "../include/match.h"
#include "../include/chell/chell.h"
#include "../../common/include/thread.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

Match::Match():
    keep_running(true),
    b2world(GRAVITY),
    world(&this->b2world) {
}

void Match::run() {
    this->keep_running = true;
    while (this->keep_running) {

    }
}

void Match::stop() {
    this->keep_running = false;
}

Chell *Match::createChell() {
    return this->world.createChell();
}
