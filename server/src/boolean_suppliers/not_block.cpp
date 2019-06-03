#include "../../include/boolean_suppliers/not_block.h"

NotBlock::NotBlock(BooleanSupplier *boolean):
    boolean(boolean) {
}

bool NotBlock::getAsBoolean() {
    return !this->boolean->getAsBoolean();
}
