#if !defined(EDITOR_BOTON_H)
#define EDITOR_BOTON_H

#include "editor_item_grafico.h"
#include "editor_defines.h"

class Boton : public ItemGrafico
{
private:
public:
    Boton();
    virtual ~Boton();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

Boton::Boton() : ItemGrafico(DIR_IMAGEN_BOTON, IDCLASS_BOTON)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W * 2, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Boton::~Boton()
{
}

void Boton::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void Boton::abrir(YAML::Node &nodo)
{
}

#endif // EDITOR_BOTON_H
