#ifndef _CAKE_H_
#define _CAKE_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../../common/include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Cake : public Entity{
private:
	SdlTexture * texturePtr;
	Area frameArea;
public:
	explicit Cake(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Cake();
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;
};

#endif
