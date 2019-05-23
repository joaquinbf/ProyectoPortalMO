#ifndef __BODY_CREATOR_FACTORY_H__
#define __BODY_CREATOR_FACTORY_H__

#include "../include/body.h"
#include "../../common/include/creatorMessage.h"

/* Clase encargada de construir message creator para los bodies del
 * servidor */
class BodyCreatorMessageFactory {
public:
    /* Instancia un creador de un body */
    void create(const Body &body) const;
};

#endif
