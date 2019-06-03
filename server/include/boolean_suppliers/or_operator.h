#ifndef __OR_OPERATOR_H__
#define __OR_OPERATOR_H__

#include "../../include/boolean_suppliers/boolean_operator.h"

class OrOperator: public BooleanOperator {
public:
    virtual bool evualuate(bool b1, bool b2) const;
};

#endif
