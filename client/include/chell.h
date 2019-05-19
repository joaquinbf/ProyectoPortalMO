#ifndef _CHELL_H_
#define _CHELL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"

#define IDLE_TEXTURE "../resources/textures/chell-idle.png"
#define JIG_TEXTURE "../resources/textures/chell-jig.png"
#define RUNNING_TEXTURE "../resources/textures/chell-running.png"
#define STOPING_TEXTURE "../resources/textures/chell-stoping.png"

class Chell{
private:
	SdlTexture * texturePtr;
	void(Chell::* actionPtr)();
	SdlTexture idleTexture;
	SdlTexture jigTexture;
	SdlTexture runTexture;
	SdlTexture stopTexture;	
	Area frameArea;
	int framex;
	int framey;
public:	
	explicit Chell(const SdlWindow& window);
	~Chell();
	int render(const Area& renderArea);	
	void idleAction();
	void jigAction();
	void runRightAction();
	void stopRightAction();
};

#endif
