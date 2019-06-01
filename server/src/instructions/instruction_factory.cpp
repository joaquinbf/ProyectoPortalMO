#include "../../include/instructions/instruction_factory.h"

#include "../.././common/include/action.h"
#include "../../include/instructions/default_instruction.h"
#include "../../include/instructions/run_left_instruction.h"
#include "../../include/instructions/stop_left_instruction.h"
#include "../../include/instructions/run_right_instruction.h"
#include "../../include/instructions/stop_right_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include <map>
#include <cstdint>

Instruction *InstructionFactory::createInstruction(
    const Action &action,
    std::map<uint32_t, Chell *> &chells) const {
    Instruction *instruction;
    Chell *chell = chells[action.getId()];

    switch (action.getAction()) {
        case ACTION::RUN_LEFT:
            instruction = new RunLeftInstruction(chell);
            break;
        case ACTION::STOP_LEFT:
            instruction = new StopLeftInstruction(chell);
            break;
        case ACTION::RUN_RIGHT:
            instruction = new RunRightInstruction(chell);
            break;
        case ACTION::STOP_RIGHT:
            instruction = new StopRightInstruction(chell);
            break;
        default:
            instruction = new DefaultInstruction();
            break;
    }
    return instruction;
}
