#include "../../include/command/command_factory.h"
#include "../../include/command/command.h"
#include "../../include/command/default_command.h"


Command *CommandFactory::createCommand(const Action &action) const {
    Command *command;
    switch (action.getAction()) {
        default:
            command = new DefaultCommand();
            break;
    }

    return command;
}
