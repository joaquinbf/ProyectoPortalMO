#ifndef __BOOLEAN_BLOCK_H__
#define __BOOLEAN_BLOCK_H__

#include "boolean_supplier.h"

class BooleanBlock: public BooleanSupplier {
public:
    virtual ~BooleanBlock();
    virtual void addBooleanSupplier(BooleanSupplier *boolean) = 0;
};

#endif
