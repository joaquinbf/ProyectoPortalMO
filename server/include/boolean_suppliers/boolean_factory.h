#ifndef __BOOLEAN_FACTORY_H__
#define __BOOLEAN_FACTORY_H__

#include <vector>
#include "boolean_supplier.h"

class BooleanFactory {
private:
    std::vector<BooleanSupplier *> booleans;
};

#endif
