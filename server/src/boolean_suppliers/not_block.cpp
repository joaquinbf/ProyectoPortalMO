#include "../../include/boolean_suppliers/not_block.h"

NotBlock::NotBlock() {
}

void NotBlock::add(BooleanSupplier *boolean) {
    this->boolean = boolean;
}

bool NotBlock::getAsBoolean() const {
    return !this->boolean->getAsBoolean();
}
