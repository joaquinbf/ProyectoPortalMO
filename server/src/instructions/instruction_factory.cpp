#include "../../include/instructions/instruction_factory.h"

#include "../.././common/include/action.h"
#include "../../include/instructions/default_instruction.h"
#include "../../include/instructions/run_left_instruction.h"
#include "../../include/instructions/stop_left_instruction.h"
#include "../../include/instructions/run_right_instruction.h"
#include "../../include/instructions/stop_right_instruction.h"
#include "../../include/instructions/jump_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include <map>
#include <cstdint>
#include <iostream>

Instruction *InstructionFactory::createInstruction(
    const Action &action,
    std::map<uint32_t, Chell *> &chells) const {
    Instruction *instruction;
    std::cout << "CHELL ID: " << action.getId() << std::endl;
    Chell *chell = chells[action.getId()];

    switch (action.getAction()) {
        case ACTION::RUN_LEFT:
            std::cout << "inst fact: ACTION::RUN_LEFT" << std::endl;
            instruction = new RunLeftInstruction(chell);
            break;
        case ACTION::STOP_LEFT:
            std::cout << "inst fact: ACTION::STOP_LEFT" << std::endl;
            instruction = new StopLeftInstruction(chell);
            break;
        case ACTION::RUN_RIGHT:
            std::cout << "inst fact: ACTION::RUN_RIGHT" << std::endl;
            instruction = new RunRightInstruction(chell);
            break;
        case ACTION::STOP_RIGHT:
            std::cout << "inst fact: ACTION::STOP_RIGHT" << std::endl;
            instruction = new StopRightInstruction(chell);
            break;
        case ACTION::JUMP:
            std::cout << "inst fact: ACTION::JUMP" << std::endl;
            instruction = new JumpInstruction(chell);
            break;
        default:
            instruction = new DefaultInstruction();
            break;
    }
    return instruction;
}
