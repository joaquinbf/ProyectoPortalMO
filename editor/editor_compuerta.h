#if !defined(EDITOR_COMPUERTA_H)
#define EDITOR_COMPUERTA_H

#include "editor_item_grafico.h"
#include "editor_defines.h"
#include <yaml-cpp/yaml.h>

class CompuertaRegular : public ItemGrafico
{
private:
public:
    CompuertaRegular();
    ~CompuertaRegular();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

CompuertaRegular::CompuertaRegular() : ItemGrafico(DIR_IMAGEN_COMPUERTA_REG,
                                                   IDCLASS_COMPUERTA_REG)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

CompuertaRegular::~CompuertaRegular()
{
}

void CompuertaRegular::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void CompuertaRegular::abrir(YAML::Node &nodo)
{
}

/*****************************************************************************/
class CompuertaAND : public ItemGrafico
{
private:
public:
    CompuertaAND();
    ~CompuertaAND();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

CompuertaAND::CompuertaAND() : ItemGrafico(DIR_IMAGEN_COMPUERTA_AND,
                                           IDCLASS_COMPUERTA_AND)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

CompuertaAND::~CompuertaAND()
{
}

void CompuertaAND::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void CompuertaAND::abrir(YAML::Node &nodo)
{
}

/*****************************************************************************/
class CompuertaOR : public ItemGrafico
{
private:
public:
    CompuertaOR();
    ~CompuertaOR();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

CompuertaOR::CompuertaOR() : ItemGrafico(DIR_IMAGEN_COMPUERTA_OR,
                                         IDCLASS_COMPUERTA_OR)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

CompuertaOR::~CompuertaOR()
{
}

void CompuertaOR::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void CompuertaOR::abrir(YAML::Node &nodo)
{
}

#endif // EDITOR_COMPUERTA_H
