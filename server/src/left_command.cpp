#include "../include/left_command.h"

LeftCommand::LeftCommand(Chell *chell):
    chell(chell) {
}

void LeftCommand::execute() {
    this->chell->left();
}
