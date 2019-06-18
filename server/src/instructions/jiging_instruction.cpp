#include "../../include/instructions/jiging_instruction.h"
#include "../../include/bodies/chell/chell.h"

JigingInstruction::JigingInstruction(Chell *chell):
    chell(chell) {
}

void JigingInstruction::execute() {
    // TODO: cambiar, debe estar en state.
    this->chell->changeStateToJiging();
}
