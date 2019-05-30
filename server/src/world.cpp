#include "../include/world.h"
#include "../include/body.h"
#include "../include/chell/chell.h"
#include "../../common/include/protected_queue.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"


World::World(b2World *b2world):
    b2world(b2world),
    body_count(0) {
}

World::~World() {
    for (Body *body: this->bodies) {
        delete body;
    }
}

Chell *World::createChell() {
    std::lock_guard<std::mutex> lg(this->m);
    float x = 0;
    float y = 0;
    Chell *chell = new Chell(this->body_count,
                             this->b2world,
                             x,
                             y);
    this->chells[chell->getBodyId()] = chell;
    this->bodies.push_back(chell);
    this->body_count++;
    return chell;
}

ProtectedQueue<Command *> *World::getCommandQueue() {
    return &this->command_queue;
}

ProtectedQueue<Update> *World::getUpdateQueue() {
    return &this->update_queue;
}

void World::step() {
    this->executeCommands();
}

void World::executeCommands() {
    Command *command;
    while (this->command_queue.try_pop(command)) {
        command->execute();
        delete command;
    }
}
