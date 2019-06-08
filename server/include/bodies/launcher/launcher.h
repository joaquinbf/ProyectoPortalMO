#ifndef __LAUNCH_H__
#define __LAUNCH_H__

#include "../body.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

class World;

class Launcher: public Body {
private:
    const float WIDTH = 1.00;
    const float HEIGHT = 1.00;

public:
    /* Instancia un launcher de id 'body_id' sobre world en la
     * posicion (x, y) */
    Launcher(uint32_t body_id, World *world, float x, float y);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body);
};

#endif
