#ifndef _PIN_INSTRUCTION_H_
#define _PIN_INSTRUCTION_H_

#include "instruction.h"

class Chell;

class PinInstruction : public Instruction {

public:
	explicit PinInstruction();
    ~PinInstruction();
    virtual void execute() override;	
};

#endif