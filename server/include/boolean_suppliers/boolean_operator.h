#ifndef __OPERATOR_H__
#define __OPERATOR_H__

#include "boolean_supplier.h"

class BooleanOperator {
public:
    virtual ~BooleanOperator();
    virtual bool evaluate(bool b1, bool b2) = 0;
};

#endif
