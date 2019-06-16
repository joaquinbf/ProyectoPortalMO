#include "editor_compuerta.h"
#include "editor_defines.h"
#include "editor_listado_de_activables.h"

Compuerta::Compuerta(QString direccionSprite, unsigned idClass) : ItemGrafico(direccionSprite, idClass)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

Compuerta::~Compuerta()
{
}

void Compuerta::eliminar(ComponenteCompuerta *componente)
{
    this->logica.remove(componente);
    //this->componentes.removeOne(componente);
}

void Compuerta::agregar(ComponenteCompuerta *componente)
{
    item_logica_t item;
    this->logica[componente] = item;
    //this->componentes.append(componente);
}

void Compuerta::agregar(QList<ComponenteCompuerta *> componentes)
{
    for (int i = 0; i < componentes.size(); i++)
    {
        item_logica_t item;
        this->logica[componentes[i]] = item;
    }

    //this->componentes.append(componentes);
}

void Compuerta::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    ListadoDeActivables listadoDeActivables;
    listadoDeActivables.setLogica(&(this->logica));
/*     listadoDeActivables.setWindowTitle("Logica de la Compuerta");
    for (int i = 0; i < this->componentes.size(); ++i)
    {
        QString nombre = this->componentes[i]->getNombre();
        QString tipo = this->componentes[i]->getTipoStr();
        listadoDeActivables.agregarElemento(nombre, tipo);
    } */

    listadoDeActivables.setModal(true);
    listadoDeActivables.exec();
}