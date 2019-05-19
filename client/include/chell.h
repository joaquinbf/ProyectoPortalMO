#ifndef _CHELL_H_
#define _CHELL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"

#define IDLE_TEXTURE "../resources/textures/chell-idle.png"
#define JIG_TEXTURE "../resources/textures/chell-jig.png"
#define RUNNING_TEXTURE "../resources/textures/chell-running.png"
#define STOPING_TEXTURE "../resources/textures/chell-stoping.png"
#define TURN_TEXTURE "../resources/textures/chell-turn.png"

class Chell{
private:
	SdlTexture * texturePtr;
	void(Chell::* actionPtr)();
	SdlTexture idleTexture;
	SdlTexture jigTexture;
	SdlTexture runTexture;
	SdlTexture stopTexture;
	SdlTexture turnTexture;	
	Area frameArea;
	int framex;
	int framey;
	int direction; //0 izquierda 1 derecha
	bool turning;
	bool running;
public:	
	explicit Chell(const SdlWindow& window);
	~Chell();
	int render(const Area& renderArea);	
	void idleAction();
	void jig();
	void jigAction();
	void run(int dir);
	void runAction();
	void stop(int dir);
	void stopAction();
	void turn(int dir);
	void turnAction();
};

#endif
