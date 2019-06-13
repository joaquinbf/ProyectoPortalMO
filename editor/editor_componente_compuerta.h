#if !defined(EDITOR_COMPONENTE_COMPUERTA_H)
#define EDITOR_COMPONENTE_COMPUERTA_H

#include <QString>

class ComponenteCompuerta
{
public:
    ComponenteCompuerta();
    virtual ~ComponenteCompuerta() = 0;
    virtual QString getNombre() = 0;
    virtual QString getTipoStr() = 0;
};

#endif // EDITOR_COMPONENTE_COMPUERTA_H
