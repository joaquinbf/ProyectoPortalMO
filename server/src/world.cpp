#include "../include/world.h"

#include "../include/bodies/body.h"
#include "../include/bodies/chell/chell.h"
#include "../include/instructions/instruction.h"
#include "../include/instructions/instruction_factory.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include <cstdint>
#include <vector>
#include <list>
#include <iostream>

World::World():
    b2world(new b2World(GRAVITY)),
    body_count(0),
    b2world_is_internal(true) {
}

World::World(b2World *b2world):
    b2world(b2world),
    body_count(0),
    b2world_is_internal(false) {
}

World::~World() {
    this->deleteBodies();
    this->deleteB2WorldIfInternal();
}

Chell *World::createChell(float x, float y) {
    Chell *chell = new Chell(this->body_count, this->b2world, x, y);
    this->body_count++;
    this->bodies.push_back(chell);
    this->chells[chell->getBodyId()] = chell;
    return chell;
}

Block *World::createSquareMetalBlock(float x, float y) {
    Shape *shape = new SquareShape();
    Material *material = new MetalMaterial();
    Block *block = new Block(this->body_count, this->b2world,
                             x, y,
                             shape, material);
    this->bodies.push_back(block);
    this->body_count++;
    return block;
}

Block *World::createSquareStoneBlock(float x, float y) {
    Shape *shape = new SquareShape();
    Material *material = new StoneMaterial();
    Block *block = new Block(this->body_count, this->b2world,
                             x, y,
                             shape, material);
    this->bodies.push_back(block);
    this->body_count++;
    return block;
}

std::list<Update> World::getNewPlayerUpdates() const {
    return this->getUpdatesWithCommand(COMMAND::CREATE_COMMAND);
}

std::list<Update> World::getUpdates() const {
    return this->getUpdatesWithCommand(COMMAND::UPDATE_COMMAND);
}

std::list<Update> World::getUpdatesForAwakeBodies() const {
    std::list<Update> updates;

    b2Body *b2body = this->b2world->GetBodyList();
    while (b2body != 0) {
        if (b2body->IsAwake()) {
            Body *body = (Body *) b2body->GetUserData();
            Update update = body->createUpdate(COMMAND::UPDATE_COMMAND);
            std::cout << "STATUS : " << update.getStatus() << std::endl;
            updates.push_back(update);
        }
        b2body = b2body->GetNext();
    }

    return updates;
}


void World::step() {
    this->b2world->Step(this->TIME_STEP,
                        this->VELOCITY_ITERATIONS,
                        this->POSITION_ITERATIONS);
}

void World::createWorldOne() {
    for (int i = 0; i < 4; i++) {
        this->createChell(200 * i, 0);
    }

    for (int i = 0; i < 7; i++) {
        this->createSquareMetalBlock(200 * i, -300);
    }
}

void World::applyAction(const Action &action) {
    InstructionFactory insf;
    Instruction *instruction = insf.createInstruction(action, this->chells);
    instruction->execute();
    delete instruction;
}

void World::applyStateActions() {
    for (Body *body: this->bodies) {
        body->applyStateAction();
    }
}


void World::deleteBodies() {
    for (Body *body: this->bodies) {
        delete body;
    }
}

void World::deleteB2WorldIfInternal() {
    if (this->b2world_is_internal) {
        delete this->b2world;
    }
}

std::list<Update> World::getUpdatesWithCommand(COMMAND command) const {
    std::list<Update> lista;

    for (Body *body: this->bodies) {
        Update update = body->createUpdate(command);
        lista.emplace_back(update);
        std::cout << "STATUS : " << update.getStatus() << std::endl;
    }

    return lista;
}
