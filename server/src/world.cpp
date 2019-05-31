#include "../include/world.h"
#include "../include/body.h"
#include "../include/chell/chell.h"
#include "../../common/include/protected_queue.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
// TODO: Borrar
#include <iostream>


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
    std::cout << "Chell *World::createChell() " << std::endl;
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

void World::oneStep() {
    std::cout << "void World::oneStep()" << std::endl;
    this->executeCommands();
    this->step();
    this->enqueueUpdatesForActiveBodies();
}

void World::executeCommands() {
    Command *command;
    while (this->command_queue.try_pop(command)) {
        command->execute();
        delete command;
    }
}

void World::step() {
    this->b2world->Step(this->TIME_STEP,
                        this->VELOCITY_ITERATIONS,
                        this->POSITION_ITERATIONS);
}

void World::enqueueUpdatesForActiveBodies() {
    std::cout << "void World::enqueueUpdatesForActiveBodies() " << std::endl;
    b2Body *b2body = this->b2world->GetBodyList();
    for (; b2body != 0; b2body = b2body->GetNext()) {
        if (b2body->IsActive()) {
            Body *body = (Body *) b2body->GetUserData();
            this->enqueueUpdateForBody(body);
        }
    }
}

void World::enqueueUpdateForBody(Body *body) {
    Update update = body->createUpdate(COMMAND::UPDATE_COMMAND);
    this->update_queue.push(update);
}
