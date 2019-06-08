#include "editor_personaje_chell.h"
#include "editor_defines.h"

PersonajeChell::PersonajeChell(unsigned idColor, QString nombre) : ItemGrafico(DIR_IMAGEN_CHELL_A, IDCLASS_CHELL),
    idColor(idColor), nombre(nombre)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

PersonajeChell::~PersonajeChell()
{

}

void PersonajeChell::guardar(YAML::Node &nodo) {
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
}

void PersonajeChell::abrir(YAML::Node &nodo) {
    
}
