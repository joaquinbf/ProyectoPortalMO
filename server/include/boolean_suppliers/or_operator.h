#ifndef __OR_OPERATOR_H__
#define __OR_OPERATOR_H__

#include "boolean_operator.h"

class OrOperator: public BooleanOperator {
public:
    virtual bool evaluate(bool b1, bool b2);
};

#endif
