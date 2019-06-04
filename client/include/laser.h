#ifndef _LASER_H_
#define _LASER_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../../common/include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Laser : public Entity{
private:
	SdlTexture * texturePtr;
	Area frameArea;
public:
	explicit Laser(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height,uint32_t direction);
	~Laser();
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;	
};

#endif
