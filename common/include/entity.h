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
protected:
	uint32_t posx;
	uint32_t posy;
	uint32_t width;
	uint32_t height;
	uint32_t direction; //0 izquierda 1 derecha
public:
	Entity(uint32_t x,uint32_t y,uint32_t w,uint32_t h,uint32_t d)
		: posx(x),posy(y),width(w),height(h),direction(d){}
	virtual ~Entity(){}
	virtual void render(int chellPosX,int chellPosY,int width,int height){}
	virtual void update(const Update&){}
};


#endif
