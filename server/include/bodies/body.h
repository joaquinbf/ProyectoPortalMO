#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../common/include/types.h"
#include "../../../common/include/update.h"
#include <cstdint>

class Body {
protected:
    const uint32_t BODY_ID;
    b2Body *b2body;

public:
    /* Instancia un cuerpo con identificador 'body_id' */
    Body(uint32_t body_id);

    /* Libera los recursos utilizados */
    virtual ~Body();

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const = 0;

    /* Devuelve un identificador del cuerpo */
    uint32_t getBodyId() const;

    /* Aplica una accion sobre el cuerpo dependiendo de su estado */
    virtual void applyStateAction();
};

#endif
