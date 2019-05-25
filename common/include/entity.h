#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "update.h"

enum ENTITY: uint8_t {
	CHELL,
	STONE_BLOCK,
	METAL_BLOCK,
	METAL_TRIAG_BLOCK,
	LAUNCH_BLOCK
};

class Entity {
public:
	Entity(){}
	virtual ~Entity(){}
	virtual void render(int resx,int resy,int width,int height){}
	virtual void update(const Update&){}
};


#endif
