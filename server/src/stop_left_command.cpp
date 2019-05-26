#include "../include/stop_left_command.h"

void StopLeftCommand::execute(Chell *chell) {
    chell->stop();
}
