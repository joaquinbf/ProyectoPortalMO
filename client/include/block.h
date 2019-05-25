#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../../common/include/entity.h"
#include "../../common/include/status.h"
#include "../../common/include/update.h"

#define METAL_TEXTURE "../resources/textures/blocks/metal.png"
#define METAL_TRIAG_TEXTURE "../resources/textures/blocks/metal-triag.png"
#define STONE_TEXTURE "../resources/textures/blocks/stone.png"
#define LAUNCH_TEXTURE "../resources/textures/blocks/launch.png"

class Block : public Entity{
private:
	SdlTexture* texturePtr;
	Area frameArea;
	ENTITY entity;
public:
	explicit Block(const TextureManager& tm,const ENTITY e,uint32_t x, uint32_t y, 
		uint32_t width, uint32_t height);
	~Block();
	void setDirection(uint32_t dir);
	void render(int resx,int resy,int width,int height) override;
	void update(const Update& update) override;	
};

#endif
