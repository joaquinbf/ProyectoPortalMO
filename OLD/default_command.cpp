#include "../include/default_command.h"
#include <iostream>

DefaultCommand::DefaultCommand() {
    std::cout << "command: DEFAULT" << std::endl;
}

void DefaultCommand::execute(World *world) {
}
