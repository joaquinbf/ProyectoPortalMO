#ifndef __AND_OPERATOR_H__
#define __AND_OPERATOR_H__

#include "boolean_supplier.h"
#include "boolean_operator.h"

class AndOperator: public BooleanOperator {
public:
    virtual bool evaluate(BooleanSupplier *b1, BooleanSupplier *b2);
};

#endif
