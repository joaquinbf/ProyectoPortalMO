#if !defined(EDITOR_BLOQUE_METAL)
#define EDITOR_BLOQUE_METAL

#include "editor_item_grafico.h"
#include "editor_defines.h"

class BloqueDeMetal : public ItemGrafico
{
private:
    /* data */
public:
    BloqueDeMetal();
    virtual ~BloqueDeMetal();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

BloqueDeMetal::BloqueDeMetal() : ItemGrafico(DIR_IMAGEN_BLOQUE_METAL, IDCLASS_BLOQUE_METAL)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

BloqueDeMetal::~BloqueDeMetal()
{
}

void BloqueDeMetal::guardar(YAML::Node &nodo) {
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void BloqueDeMetal::abrir(YAML::Node &nodo) {
    
}


#endif // EDITOR_BLOQUE_METAL
