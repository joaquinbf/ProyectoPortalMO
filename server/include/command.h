#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "chell.h"

class Command {
public:
    virtual void execute(Chell *chell) = 0;
    virtual ~Command();
};

#endif
