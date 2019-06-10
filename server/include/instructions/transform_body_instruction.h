#ifndef __TRANSFORM_BODY_INSTRUCTION_H__
#define __TRANSFORM_BODY_INSTRUCTION_H__

#include "instruction.h"

class Body;

class TransformBodyInstruction: public Instruction {
private:
    Body *body;

public:
    TransformBodyInstruction(Body *body);
    virtual void execute() override;
};

#endif
