#ifndef EDITOR_BLOQUE_DE_ROCA_H
#define EDITOR_BLOQUE_DE_ROCA_H

#include "editor_item_grafico.h"

class BloqueDeRoca : public ItemGrafico
{
public:
    BloqueDeRoca();
    ~BloqueDeRoca();

    virtual void guardar(/*YAML::Node &nodo*/);
};

#endif // EDITOR_BLOQUE_DE_ROCA_H
