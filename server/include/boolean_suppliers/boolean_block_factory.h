#ifndef __BOOLEAN_BLOCK_FACTORY_H__
#define __BOOLEAN_BLOCK_FACTORY_H__

#include "boolean_block.h"
#include "binary_block.h"
#include "and_operator.h"
#include "or_operator.h"
#include <vector>

class BooleanBlockFactory {
private:
    std::vector<BooleanBlock *> blocks;
    AndOperator and_operator;
    OrOperator or_operator;

public:
    ~BooleanBlockFactory();
    BooleanBlock *createAndBlock();
    BooleanBlock *createOrBlock();
};

#endif
