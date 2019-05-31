#include "../include/left_command.h"
#include <iostream>

LeftCommand::LeftCommand(Chell *chell):
    chell(chell) {
}

void LeftCommand::execute(World *world) {
    this->chell->left();
    std::cout << "command: LEFT" << std::endl;
}
