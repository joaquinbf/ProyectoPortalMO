#ifndef __RUN_LEFT_COMMAND_H__
#define __RUN_LEFT_COMMAND_H__

#include "command.h"
#include "chell.h"

class RunLeftCommand: public Command {
public:
    virtual void execute(Chell *chell) override;
};

#endif
