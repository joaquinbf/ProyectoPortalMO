#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "../include/Area.h"
#include "../include/SdlTexture.h"

#define BACKGROUND_TEXTURE "../resources/textures/background.jpg"
#define SIZE_X 600
#define SIZE_Y 400

class Background{
private: 
	SdlTexture backgroundTexture;
	int widthRendered;
	int heightRendered;
public:
	explicit Background(const SdlWindow& window);
	~Background();
	int render(int x, int y,int resx, int resy);
};

#endif
