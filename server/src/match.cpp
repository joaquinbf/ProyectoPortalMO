#include "../include/match.h"
#include "../include/command/command.h"
#include "../include/chell/chell.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

Match::Match():
    keep_running(true),
    b2world(GRAVITY),
    world(&this->b2world),
    broadcaster(this->world.getUpdateQueue()) {
}

void Match::run() {
    this->keep_running = true;
    this->broadcaster.start();

    while (this->keep_running) {
        this->world.step();
    }

    this->broadcaster.stop();
    this->broadcaster.join();
}

void Match::stop() {
    this->keep_running = false;
}

Chell *Match::createChell() {
    return this->world.createChell();
}

ProtectedQueue<Command *> *Match::getCommandQueue() {
    return this->world.getCommandQueue();
}

ProtectedQueue<Update> *Match::getUpdateQueue() {
    return this->world.getUpdateQueue();
}
