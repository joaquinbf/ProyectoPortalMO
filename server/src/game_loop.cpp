#include "../include/game_loop.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../include/world.h"
#include "../include/instructions/instruction_factory.h"
#include "../include/instructions/instruction.h"

GameLoop::GameLoop(
    World *world,
    std::set<Body *> *bodies,
    std::deque<Update> *internal_updates):
    world(world),
    bodies(bodies),
    internal_updates(internal_updates) {
}

void GameLoop::executeExternalInput(ProtectedQueue<Action> *inputs) {
    std::map<uint32_t, Chell *> *chells = this->world->getChells();
    InstructionFactory inst_fact;
    Instruction *inst;
    Action action;

    while (inputs->try_pop(action)) {
        inst = inst_fact.createInstruction(action, *chells, this->world);
        inst->execute();
        delete inst;
    }
}

void GameLoop::step() {
    this->worldStep();
    this->applyInternalInstructions();
    this->applyStateActions();
    this->createUpdates();
}

void GameLoop::fillUpdates(ProtectedQueue<Update> *ext_updates) {

}

void GameLoop::worldStep() {
    this->world->getB2World()->Step(
        this->TIME_STEP,
        this->VELOCITY_ITERATIONS,
        this->POSITION_ITERATIONS);
}

void GameLoop::applyInternalInstructions() {

}

void GameLoop::applyStateActions() {

}

void GameLoop::createUpdates() {

}
