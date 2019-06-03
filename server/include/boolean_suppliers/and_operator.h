#ifndef __AND_OPERATOR_H__
#define __AND_OPERATOR_H__

#include "boolean_supplier.h"
#include "operator.h"

class AndOperator: public Operator {
public:
    virtual bool evaluate(BooleanSupplier *b1, BooleanSupplier *b2);
};

#endif
