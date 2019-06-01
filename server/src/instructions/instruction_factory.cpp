#include "../../include/instructions/instruction_factory.h"

#include "../.././common/include/action.h"
#include "../../include/instructions/default_instruction.h"
#include "../../include/instructions/run_left_instruction.h"
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
        default:
            instruction = new DefaultInstruction();
            break;
    }
    return instruction;
}
