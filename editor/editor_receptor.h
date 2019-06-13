#if !defined(EDITOR_RECEPTOR_H)
#define EDITOR_RECEPTOR_H

#include "editor_item_grafico.h"
#include "editor_componente_compuerta.h"
#include <QString>

class Receptor : public ItemGrafico, public ComponenteCompuerta
{
private:
    QString nombre;

public:
    Receptor();
    ~Receptor();

    virtual QString getNombre();
    virtual QString getTipoStr();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // EDITOR_RECEPTOR_H
