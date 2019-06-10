#ifndef __DELETE_BODY_INSTRUCTION_H__
#define __DELETE_BODY_INSTRUCTION_H__

#include "instruction.h"

class Body;

class DeleteBodyInstruction: public Instruction {
private:
    Body *body;

public:
    DeleteBodyInstruction(Body *body);
    virtual void execute() override;
};

#endif
