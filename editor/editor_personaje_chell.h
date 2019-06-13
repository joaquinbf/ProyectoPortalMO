#ifndef EDITOR_PERSONAJE_CHELL_H
#define EDITOR_PERSONAJE_CHELL_H

#include "editor_item_grafico.h"

#include <QString>

class PersonajeChell : public ItemGrafico
{
private:
    unsigned idColor;
    QString nombre;

public:
    PersonajeChell();
    virtual ~PersonajeChell();
};

#endif // EDITOR_PERSONAJE_CHELL_H
