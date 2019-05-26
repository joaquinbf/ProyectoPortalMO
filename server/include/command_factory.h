#ifndef __COMMAND_FACTORY_H__
#define __COMMAND_FACTORY_H__

#include "command.h"
#include "../../common/include/action.h"

/* CommandFactory crea commands que se aplican sobre los caracteres del mundo.
 * Deben ser liberados por el usuario */
class CommandFactory {
public:
    /* Instancia un command */
    Command *create(const Action &action) const;

private:
    /* Instancia un command de correr a la izquierda */
    Command *createRunLeft(const Action &action) const;
};

#endif
