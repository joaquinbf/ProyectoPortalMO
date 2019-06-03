#ifndef __BOOLEAN_FACTORY_H__
#define __BOOLEAN_FACTORY_H__

#include <vector>
#include "boolean_supplier.h"
#include "and_operator.h"
#include "or_operator.h"
#include "binary_block.h"


class BooleanFactory {
private:
    std::vector<BooleanBlock *> blocks;
    AndOperator and_operator;
    OrOperator or_operator;

public:
    BooleanBlock *createAndBlock();
    ~BooleanFactory();
};

#endif
