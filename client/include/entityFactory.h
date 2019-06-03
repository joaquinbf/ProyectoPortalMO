#ifndef _ENTITY_FACTORY_H_
#define _ENTITY_FACTORY_H_

#include "../include/SdlWindow.h"
#include "../../common/include/entity.h"
#include "../../common/include/update.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/button.h"
#include "../include/rock.h"
#include "../include/gate.h"

class EntityFactory{
public:
	EntityFactory();
	~EntityFactory();
	Entity* create(const Update& up, const TextureManager& tm);
};

#endif
