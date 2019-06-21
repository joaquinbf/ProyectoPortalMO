#include "../include/game_loop.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../include/world.h"
#include "../include/instructions/instruction_factory.h"
#include "../include/instructions/instruction.h"

GameLoop::GameLoop(World *world):
    world(world) {
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

}

void GameLoop::fillUpdates(ProtectedQueue<Update> *ext_updates) {

}
