#ifndef __NOT_BLOCK_H__
#define __NOT_BLOCK_H__

#include "boolean_supplier.h"
#include "boolean_block.h"

class NotBlock: public BooleanBlock {
private:
    BooleanSupplier *boolean;

public:
    NotBlock();
    virtual void add(BooleanSupplier *boolean);
    virtual bool getAsBoolean() const;
};

#endif
