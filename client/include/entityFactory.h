#ifndef _ENTITY_FACTORY_H_
#define _ENTITY_FACTORY_H_

#include "../../common/include/creatorMesage.h"
#include "../include/SdlWindow.h"
#include "../../common/include/entity.h"
#include "../include/chell.h"

class EntityFactory{
public:
	EntityFactory();
	~EntityFactory();
	Entity* create(CreatorMesage cm,const SdlWindow& window);
};

#endif
