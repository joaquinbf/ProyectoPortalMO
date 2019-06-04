#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../include/update.h"

class Entity {
protected:
	int32_t posx;
	int32_t posy;
	uint32_t width;
	uint32_t height;
	uint32_t direction; //0 izquierda 1 derecha
public:
	Entity(int32_t x,int32_t y,uint32_t w,uint32_t h,uint32_t d)
		: posx(x),posy(y),width(w),height(h),direction(d){}
	virtual ~Entity(){}
	virtual void step(){}
	virtual void render(int32_t chellPosX,int32_t chellPosY,int width,int height,
		float scale){}
	virtual void update(const Update&){}
};


#endif
