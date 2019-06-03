#ifndef __OPERATOR_H__
#define __OPERATOR_H__

#include "boolean_supplier.h"

class Operator {
public:
    virtual ~Operator();
    virtual bool evaluate(BooleanSupplier *b1, BooleanSupplier *b2) = 0;
};

#endif
