#ifndef _CROSSHAIR_H_
#define _CROSSHAIR_H_

#include <SDL2/SDL.h>

#include "../include/textureManager.h"
#include "../include/SdlTexture.h"
#include "../include/Area.h"

class Crosshair{
	SdlTexture * texturePtr;
	Area frameArea;
public:
	explicit Crosshair(const TextureManager& tm);
	~Crosshair();
	void render();
};

#endif
