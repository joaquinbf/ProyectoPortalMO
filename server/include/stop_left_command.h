#ifndef __STOP_LEFT_COMMAND_H__
#define __STOP_LEFT_COMMAND_H__

#include "command.h"

class StopLeftCommand: public Command {
public:
    virtual void execute(Chell *chell);
};

#endif
