#if !defined(EDITOR_COMPONENTE_COMPUERTA_H)
#define EDITOR_COMPONENTE_COMPUERTA_H

#include <QString>
#include "editor_item_grafico.h"

class ComponenteCompuerta : public ItemGrafico
{
private:
public:
    ComponenteCompuerta(QString direccionSprite, unsigned idClass);
    virtual ~ComponenteCompuerta();
    virtual QString getNombre() = 0;
    virtual QString getTipoStr() = 0;
};

#endif // EDITOR_COMPONENTE_COMPUERTA_H
