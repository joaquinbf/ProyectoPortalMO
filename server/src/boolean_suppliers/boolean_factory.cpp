#include "../../include/boolean_suppliers/boolean_factory.h"

BooleanBlock *BooleanFactory::createAndBlock() {
    BinaryBlock *binary = new BinaryBlock(&this->and_operator);
    this->blocks.push_back(binary);
    return binary;
}

BooleanBlock *BooleanFactory::createOrBlock() {
    BinaryBlock *binary = new BinaryBlock(&this->or_operator);
    this->blocks.push_back(binary);
    return binary;
}

BooleanFactory::~BooleanFactory() {
    for (BooleanBlock *block: this->blocks) {
        delete block;
    }
}
