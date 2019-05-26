#include "../include/run_left_command.h"
#include <iostream>

void RunLeftCommand::execute(Chell *chell) {
    std::cout << "run left command, chell ptr: " << chell << std::endl;
    chell->runLeft();
}
