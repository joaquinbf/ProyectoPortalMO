#ifndef EDITOR_ITEM_GRAFICO_H
#define EDITOR_ITEM_GRAFICO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <string>
#include <QPointF>
#include <yaml-cpp/yaml.h>

class ItemGrafico : public QGraphicsPixmapItem
{
protected:
    QPixmap sprite;
    unsigned idClass;

public:
    ItemGrafico(QString direccionSprite, unsigned idClass);
    virtual ~ItemGrafico();

    int getIdCelda();
    virtual void guardar(YAML::Node &nodo) = 0;
    virtual void abrir(YAML::Node &nodo) = 0;
    virtual void agregarElemento(ItemGrafico *elemento);

    virtual QString getNombre();
    virtual QString getTipoStr();
};

#endif // EDITOR_ITEM_GRAFICO_H
