#ifndef __DEFAULT_COMMAND_H__
#define __DEFAULT_COMMAND_H__

#include "command.h"
#include "chell.h"

class DefaultCommand: public Command {
public:
    virtual void execute(Chell *chell) override;
};

#endif
