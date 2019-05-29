#ifndef __COMMAND_FACTORY_H__
#define __COMMAND_FACTORY_H__

#include "command.h"
#include "../../../common/include/action.h"

class CommandFactory {
public:
    /* Instancia un command basado en la accion entragada, el cual en caso
     * de no estar idenficado devolvera un commando por default que no
     * realizara accion alguna.
     * Debe ser liberado por el usuario. */
    Command *createCommand(const Action &action) const;
};

#endif
