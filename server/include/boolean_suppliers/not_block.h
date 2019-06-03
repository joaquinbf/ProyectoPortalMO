#ifndef __NOT_BLOCK_H__
#define __NOT_BLOCK_H__

#include "boolean_supplier.h"

class NotBlock: public BooleanSupplier {
private:
    BooleanSupplier *boolean;

public:
    NotBlock(BooleanSupplier *boolean);
    virtual bool getAsBoolean() const;
};

#endif
