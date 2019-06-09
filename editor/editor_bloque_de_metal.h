#if !defined(EDITOR_BLOQUE_METAL)
#define EDITOR_BLOQUE_METAL

#include "editor_item_grafico.h"

class BloqueDeMetal : public ItemGrafico
{
private:
public:
    BloqueDeMetal();
    virtual ~BloqueDeMetal();

    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};



#endif // EDITOR_BLOQUE_METAL
