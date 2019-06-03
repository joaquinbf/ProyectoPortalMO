#ifndef __BOOLEAN_FACTORY_H__
#define __BOOLEAN_FACTORY_H__

#include <vector>
#include "boolean_supplier.h"
#include "and_operator.h"
#include "or_operator.h"
#include "binary_block.h"

/* BooleanFactory instancia bloques booleanos y se encarga de su
 * liberacion de memoria, es decir, no debe ser hecha por el
 * usuario */
class BooleanFactory {
private:
    std::vector<BooleanBlock *> blocks;
    AndOperator and_operator;
    OrOperator or_operator;

public:
    /* Instancia un bloque que evalua a sus miembro con AND */
    BooleanBlock *createAndBlock();

    /* Instancia un bloque que evalua a sus miembros con OR */
    BooleanBlock *createOrBlock();

    /* Libera los recursos utilizados */
    ~BooleanFactory();
};

#endif
