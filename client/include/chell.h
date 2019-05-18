#ifndef _CHELL_H_
#define _CHELL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"

#define IDLE_TEXTURE "../resources/textures/chell-idle.png"

class Chell{
private:
	SdlTexture texture;
	Area area;
public:
	explicit Chell(const SdlWindow& window);
	~Chell();
	int render(int x, int y);	
};

#endif
