#include "editor_bloque_de_metal.h"
#include "editor_defines.h"

BloqueDeMetal::BloqueDeMetal() : ItemGrafico(DIR_IMAGEN_BLOQUE_METAL,
                                             IDCLASS_BLOQUE_METAL)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

BloqueDeMetal::~BloqueDeMetal()
{
}

void BloqueDeMetal::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void BloqueDeMetal::abrir(YAML::Node &nodo)
{
}