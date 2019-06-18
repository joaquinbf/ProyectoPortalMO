#ifndef __JIGING_INSTRUCTION_H__
#define __JIGING_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class JigingInstruction: public Instruction {
private:
    Chell *chell;

public:
    /* Instancia una instruccion de bailar */
    JigingInstruction(Chell *chell);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
