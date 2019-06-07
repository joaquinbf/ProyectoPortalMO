#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "../include/Area.h"
#include "../include/SdlTexture.h"

#define BACKGROUND_TEXTURE "../resources/textures/backgrounds/1.jpg"

class Background{
private: 
	SdlTexture backgroundTexture;
	uint32_t resx;
	uint32_t resy;
	uint32_t widthRendered;
	uint32_t heightRendered;
public:
	explicit Background(const SdlWindow& window);
	~Background();
	void render(int x, int y,int resx, int resy,float scale);
};

#endif
