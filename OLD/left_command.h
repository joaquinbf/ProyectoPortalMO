#ifndef __LEFT_COMMAND_H__
#define __LEFT_COMMAND_H__

#include "command.h"
#include "chell/chell.h"

class LeftCommand: public Command {
private:
    Chell *chell;

public:
    LeftCommand(Chell *chell);
    virtual void execute(World *world) override;
};

#endif
