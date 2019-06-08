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
    PersonajeChell(unsigned idColor, QString nombre);
    virtual ~PersonajeChell();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);

};

#endif // EDITOR_PERSONAJE_CHELL_H
