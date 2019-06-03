#ifndef __AND_OPERATOR_H__
#define __AND_OPERATOR_H__

#include "boolean_operator.h"

class AndOperator: public BooleanOperator {
public:
    virtual bool evaluate(bool b1, bool b2);
};

#endif
