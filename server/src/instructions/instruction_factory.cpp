#include "../../include/instructions/instruction_factory.h"

#include "../../include/world.h"
#include "../.././common/include/action.h"
#include "../../include/instructions/default_instruction.h"
#include "../../include/instructions/run_left_instruction.h"
#include "../../include/instructions/stop_left_instruction.h"
#include "../../include/instructions/run_right_instruction.h"
#include "../../include/instructions/stop_right_instruction.h"
#include "../../include/instructions/jump_instruction.h"
#include "../../include/instructions/fire_portal_instruction.h"
#include "../../include/instructions/pinInstruction.h"
#include "../../include/instructions/press_grab_instruction.h"
#include "../../include/instructions/stop_grab_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/portal/portal.h"
#include <map>
#include <cstdint>
#include <iostream>

Instruction *InstructionFactory::createInstruction(
    const Action &action,
    std::map<uint32_t, Chell *> &chells,
    World* world) const {
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
        case ACTION::JUMP:
            instruction = new JumpInstruction(chell);
            break;
        case ACTION::PING:
            instruction = new PinInstruction(world,action.getId(),action.getParam1(),action.getParam2());
            break;
        case ACTION::FIRE1:
            instruction = new FirePortalInstruction(
                chell, NPORTAL1, action.getParam1(), action.getParam2());
            break;
        case ACTION::FIRE2:
            instruction = new FirePortalInstruction(
                chell, NPORTAL2, action.getParam1(), action.getParam2());
            break;
        case ACTION::GRAB:
            instruction = new PressGrabInstruction(chell);
            break;
        case ACTION::STOP_GRAB:
            instruction = new StopGrabInstruction(chell);
            break;
        default:
            instruction = new DefaultInstruction();
            break;
    }
    return instruction;
}
