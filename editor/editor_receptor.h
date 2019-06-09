#if !defined(EDITOR_RECEPTOR_H)
#define EDITOR_RECEPTOR_H

#include "editor_item_grafico.h"
#include "editor_defines.h"

class Receptor : public ItemGrafico
{
private:
public:
    Receptor();
    ~Receptor();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

Receptor::Receptor() : ItemGrafico(DIR_IMAGEN_RECEPTOR, IDCLASS_RECEPTOR)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Receptor::~Receptor()
{
}

void Receptor::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void Receptor::abrir(YAML::Node &nodo)
{
}

#endif // EDITOR_RECEPTOR_H
