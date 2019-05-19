#ifndef _CHELL_H_
#define _CHELL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"

#define IDLE_TEXTURE "../resources/textures/chell-idle.png"
#define JIG_TEXTURE "../resources/textures/chell-jig.png"

class Chell{
private:
	SdlTexture * texturePtr;
	void(Chell::* actionPtr)();
	SdlTexture idleTexture;
	SdlTexture jigTexture;
	Area frameArea;
	int framex;
	int framey;
public:
	explicit Chell(const SdlWindow& window);
	~Chell();
	int render(int x, int y);	
	void idleAction();
	void jigAction();
};

#endif
