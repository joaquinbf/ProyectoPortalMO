#include "../../include/instructions/jig_instruction.h"
#include "../../include/bodies/chell/chell.h"

JigInstruction::JigInstruction(Chell *chell):
    chell(chell) {
}

void JigInstruction::execute() {
    // TODO: cambiar, debe estar en state.
    this->chell->changeStateToJiging();
}
