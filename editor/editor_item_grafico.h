#ifndef EDITOR_ITEM_GRAFICO_H
#define EDITOR_ITEM_GRAFICO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <string>
#include <yaml-cpp/yaml.h>

class ItemGrafico : public QGraphicsPixmapItem
{
protected:
    QPixmap sprite;
    unsigned idClass;

public:
    ItemGrafico(QString direccionSprite, unsigned idClass);
    virtual ~ItemGrafico();

    virtual void guardar(/*YAML::Node &nodo*/);
};

#endif // EDITOR_ITEM_GRAFICO_H
