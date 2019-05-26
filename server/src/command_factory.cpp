#include "../include/command_factory.h"

Command *CommandFactory::create(const Action &action) const {
    Command *command;
    switch (action.getAction()) {
        case ACTION::RUN_LEFT:
            command =  this->createRunLeft(action);
            break;
        case ACTION::STOP_LEFT:
            command = this->createStopLeft(action);
            break;
        default:
            command = this->createDefault();
            break;
    }
    return command;
}

Command *CommandFactory::createRunLeft(const Action &action) const {
    return new RunLeftCommand();
}

Command *CommandFactory::createStopLeft(const Action &action) const {
    return new StopLeftCommand();
}

Command *CommandFactory::createDefault() const {
    return new DefaultCommand();
}
