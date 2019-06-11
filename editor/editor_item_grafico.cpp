#include "editor_item_grafico.h"
#include "editor_defines.h"

#include <QPointF>
#include <QtMath>

ItemGrafico::ItemGrafico(QString direccionSprite, unsigned idClass) : sprite(direccionSprite), idClass(idClass)
{
}

ItemGrafico::~ItemGrafico()
{
}

int ItemGrafico::getIdCelda()
{
    QPointF posicion = this->scenePos();

    int i = qFloor(posicion.x() / CELL_SIZE_W);
    int j = qFloor(posicion.y() / CELL_SIZE_H);
    int columnas = qFloor(WINDOWS_SIZE_W / CELL_SIZE_W);
    int k = columnas * j + i;
    return k;
}

void ItemGrafico::agregarElemento(ItemGrafico *elemento)
{
    //Hacer nada
}

QString ItemGrafico::getNombre() {
    return "";
}

QString ItemGrafico::getTipoStr() {
    return "";
}
