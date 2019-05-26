#include "../include/command_factory.h"

Command *CommandFactory::create(const Action &action) const {
    Command *command;
    switch (action.getAction()) {
        case ACTION::RUN_LEFT:
            command =  this->createRunLeft(action);
            break;
        default:
            command = 0;
    }
    return command;
}

Command *CommandFactory::createRunLeft(const Action &action) const {
    return 0;
}
