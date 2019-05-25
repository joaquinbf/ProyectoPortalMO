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
	uint32_t direction;
public:
	explicit Block(TextureManager& tm,const ENTITY e);
	~Block();
	void setDirection(uint32_t dir);
	void render(int resx,int resy,int width,int height) override;
	void update(const Update& update) override;	
};

#endif
