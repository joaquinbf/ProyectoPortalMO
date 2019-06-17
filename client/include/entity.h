#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../../common/include/update.h"

#include "../include/SdlTexture.h"

class TextureManager;

class Entity {
protected:
	int32_t posx;
	int32_t posy;
	uint32_t width;
	uint32_t height;
	uint32_t direction; //0 izquierda 1 derecha
	SdlTexture * texturePtr;
	const TextureManager & textureManager;
public:
	Entity(int32_t x,int32_t y,uint32_t w,uint32_t h,uint32_t d,const TextureManager &tm)
		: posx(x),posy(y),width(w),height(h),direction(d),textureManager(tm){}
	virtual ~Entity(){}
	virtual void step(){}
	virtual void render(int32_t chellPosX,int32_t chellPosY,int width,int height,
		float scale){}
	virtual void update(const Update&){}
};


#endif
