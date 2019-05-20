#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "../include/Area.h"
#include "../include/SdlTexture.h"

#define BACKGROUND_TEXTURE "../resources/textures/background.jpg"

class Background{
private: 
	SdlTexture backgroundTexture;
public:
	explicit Background(const SdlWindow& window);
	~Background();
	int render(const Area& renderArea);
};

#endif
