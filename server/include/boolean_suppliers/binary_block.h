#ifndef __BINARY_BLOCK_H__
#define __BINARY_BLOCK_H__

#include "boolean_supplier.h"
#include "boolean_operator.h"
#include "boolean_block.h"
#include <vector>

class BinaryBlock: public BooleanBlock {
private:
    BooleanOperator *boolean_operator;
    std::vector<BooleanSupplier *> booleans;

public:
    BinaryBlock(BooleanOperator *boolean_operator);
    virtual bool getAsBoolean();
    virtual void addBooleanSupplier(BooleanSupplier *boolean);

};

#endif
