#include "../../include/boolean_suppliers/or_operator.h"

bool OrOperator::evaluate(BooleanSupplier *b1, BooleanSupplier *b2) {
    return b1->getAsBoolean() && b2->getAsBoolean();
}
