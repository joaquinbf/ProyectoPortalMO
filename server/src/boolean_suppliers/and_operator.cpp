#include "../../include/boolean_suppliers/and_operator.h"

bool AndOperator::evaluate(BooleanSupplier *b1, BooleanSupplier *b2) {
    return b1->getAsBoolean() && b2->getAsBoolean();
}
