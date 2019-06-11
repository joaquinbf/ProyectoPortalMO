#if !defined(EDITOR_COMPUERTA_H)
#define EDITOR_COMPUERTA_H

#include "editor_item_grafico.h"
#include "editor_defines.h"
#include "editor_listado_de_activables.h"
#include "editor_boton.h"
#include <yaml-cpp/yaml.h>

class Compuerta : public ItemGrafico
{
private:
    /* data */
protected:
    QList<ItemGrafico *> elementos;

public:
    Compuerta(QString direccionSprite, unsigned idClass);
    ~Compuerta();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
    virtual void agregarElemento(ItemGrafico *elemento);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

Compuerta::Compuerta(QString direccionSprite, unsigned idClass) : ItemGrafico(direccionSprite, idClass)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

Compuerta::~Compuerta()
{
}

void Compuerta::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void Compuerta::abrir(YAML::Node &nodo)
{
}

void Compuerta::agregarElemento(ItemGrafico *elemento)
{
    this->elementos.append(elemento);
}

void Compuerta::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    ListadoDeActivables listadoDeActivables;
    listadoDeActivables.setWindowTitle("Logica de la Compuerta");
    for (int i = 0; i < this->elementos.size(); i++)
    {
        QString nombre = this->elementos[i]->getNombre();
        QString tipo = this->elementos[i]->getTipoStr();
        listadoDeActivables.agregarElemento(nombre, tipo);
    }
    
    listadoDeActivables.setModal(true);
    listadoDeActivables.exec();
}

/****************************************************************************/

class CompuertaRegular : public Compuerta
{
private:
public:
    CompuertaRegular();
    ~CompuertaRegular();
};

CompuertaRegular::CompuertaRegular() : Compuerta(DIR_IMAGEN_COMPUERTA_REG,
                                                 IDCLASS_COMPUERTA_REG)
{
}

CompuertaRegular::~CompuertaRegular()
{
}

/*****************************************************************************/
class CompuertaAND : public Compuerta
{
private:
public:
    CompuertaAND();
    ~CompuertaAND();
};

CompuertaAND::CompuertaAND() : Compuerta(DIR_IMAGEN_COMPUERTA_AND,
                                         IDCLASS_COMPUERTA_AND)
{
}

CompuertaAND::~CompuertaAND()
{
}

/*****************************************************************************/
class CompuertaOR : public Compuerta
{
private:
public:
    CompuertaOR();
    ~CompuertaOR();
};

CompuertaOR::CompuertaOR() : Compuerta(DIR_IMAGEN_COMPUERTA_OR,
                                       IDCLASS_COMPUERTA_OR)
{
}

CompuertaOR::~CompuertaOR()
{
}

#endif // EDITOR_COMPUERTA_H
