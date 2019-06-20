#if !defined(EDITOR_FABRICA_H)
#define EDITOR_FABRICA_H

#include "editor_item_grafico.h"

class Fabrica
{
private:
    /* data */
public:
    Fabrica(/* args */);
    ~Fabrica();

    virtual ItemGrafico *generar() = 0;
};

#endif // EDITOR_FABRICA_H
