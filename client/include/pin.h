#ifndef _PIN_H_
#define _PIN_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/soundManager.h"
#include "../../common/include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"


class Pin : public Entity{
private:
	SdlTexture * texturePtr;
	Area frameArea;
public:
	explicit Pin(const TextureManager& tm,const SoundManager& sm,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Pin();
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;		
};

#endif
