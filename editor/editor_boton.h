#if !defined(EDITOR_BOTON_H)
#define EDITOR_BOTON_H

#include "editor_item_grafico.h"
#include "editor_componente_compuerta.h"
#include <QString>

class Boton : public ItemGrafico, public ComponenteCompuerta
{
private:
    QString nombre;

public:
    Boton();
    virtual ~Boton();

    virtual QString getNombre();
    virtual QString getTipoStr();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // EDITOR_BOTON_H
