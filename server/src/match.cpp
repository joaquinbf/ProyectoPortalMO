#include "../include/match.h"
#include "../include/command/command.h"
#include "../include/chell/chell.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

// TODO: Borrar
#include <iostream>

Match::Match():
    keep_running(true),
    b2world(GRAVITY),
    world(&this->b2world),
    broadcaster(this->world.getUpdateQueue()) {
}

void Match::run() {
    std::cout << "void Match::run()" << std::endl;
    this->keep_running = true;
    this->broadcaster.start();

    while (this->keep_running) {
        this->world.oneStep();
    }
}

void Match::stop() {
    this->keep_running = false;
    this->broadcaster.stop();
    this->broadcaster.join();
    std::cout << "despues del broadcaster.join()" << std::endl;
}

Chell *Match::createChell() {
    return this->world.createChell();
}

ProtectedQueue<Command *> *Match::getCommandQueue() {
    std::cout << "ProtectedQueue<Command *> *Match::getCommandQueue()"
              << std::endl;
    return this->world.getCommandQueue();
}

void Match::sendUpdatesTo(ProtectedQueue<Update> *update_queue) {
    this->broadcaster.addPlayerUpdateQueue(update_queue);
}

void Match::buildLevelOne() {
    for (int i = 0; i < 2; i++) {
        this->chells.push_back(this->world.createChell());
    }
}

Chell *Match::getAviableChell() {
    if (this->chells.empty()) {
        return 0;
    }
    Chell *chell = this->chells.back();
    this->chells.pop_back();
    return chell;
}
