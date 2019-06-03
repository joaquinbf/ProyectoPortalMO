#include "../../include/boolean_suppliers/binary_block.h"

BinaryBlock::BinaryBlock(BooleanOperator *boolean_operator):
    boolean_operator(boolean_operator) {
}

bool BinaryBlock::getAsBoolean() {
    bool acum = this->booleans.at(0);

    for (unsigned int i = 1; i < this->booleans.size(); i++) {
        bool value = this->booleans.at(i)->getAsBoolean();
        acum = this->boolean_operator->evaluate(acum, value);
    }

    return acum;
}

void BinaryBlock::addBooleanSupplier(BooleanSupplier *boolean) {
    this->booleans.push_back(boolean);
}
