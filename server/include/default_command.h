#ifndef __DEFAULT_COMMAND_H__
#define __DEFAULT_COMMAND_H__

#include "command.h"

class DefaultCommand: public Command {
public:
    DefaultCommand();
    virtual void execute(World *world) override;
};

#endif
