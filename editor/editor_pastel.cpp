#include "editor_pastel.h"
#include "editor_defines.h"

Pastel::Pastel() : ItemGrafico(DIR_IMAGEN_PASTEL, IDCLASS_PASTEL)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Pastel::~Pastel()
{
}