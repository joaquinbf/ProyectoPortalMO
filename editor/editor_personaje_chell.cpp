#include "editor_personaje_chell.h"
#include "editor_defines.h"

PersonajeChell::PersonajeChell() : ItemGrafico(DIR_IMAGEN_CHELL_A, IDCLASS_CHELL)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

PersonajeChell::~PersonajeChell() 
{
}
