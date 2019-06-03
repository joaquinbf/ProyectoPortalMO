#ifndef __BINARY_BLOCK_H__
#define __BINARY_BLOCK_H__

#include <vector>
#include "boolean_supplier.h"
#include "boolean_operator.h"
#include "boolean_block.h"

class BinaryBlock: public BooleanBlock {
private:
    const BooleanOperator *boolean_operator;
    std::vector<BooleanSupplier *> booleans;

public:
    BinaryBlock(const BooleanOperator *boolean_operator);
    virtual ~BinaryBlock();
    virtual bool getAsBoolean() const;
    virtual void add(BooleanSupplier *boolean);
};

#endif
