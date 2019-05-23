#ifndef _CHELL_H_
#define _CHELL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../../common/include/entity.h"

#define CHELL_IDLE_TEXTURE "../resources/textures/chell-idle.png"
#define CHELL_JIG_TEXTURE "../resources/textures/chell-jig.png"
#define CHELL_RUNNING_TEXTURE "../resources/textures/chell-running.png"
#define CHELL_STOPING_TEXTURE "../resources/textures/chell-stoping.png"
#define CHELL_TURN_TEXTURE "../resources/textures/chell-turn.png"
#define CHELL_JUMP_RISE_TEXTURE "../resources/textures/chell-jump-rise.png"
#define CHELL_JUMP_APEX_TEXTURE "../resources/textures/chell-jump-apex.png"
#define CHELL_JUMP_FALL_TEXTURE "../resources/textures/chell-jump-fall.png"
#define CHELL_JUMP_LAND_TEXTURE "../resources/textures/chell-jump-land.png"
#define CHELL_FIRE_TEXTURE "../resources/textures/chell-fire.png"
#define CHELL_FIRE_TO_IDLE_TEXTURE "../resources/textures/chell-fire-to-idle.png"

class Chell : public Entity{
private:
	SdlTexture * texturePtr;
	void(Chell::* actionPtr)();
	SdlTexture idleTexture;
	SdlTexture jigTexture;
	SdlTexture runTexture;
	SdlTexture stopTexture;
	SdlTexture turnTexture;
	SdlTexture jumpRiseTexture;
	SdlTexture jumpApexTexture;
	SdlTexture jumpFallTexture;
	SdlTexture jumpLandTexture;
	SdlTexture fireTexture;
	SdlTexture fireToIdleTexture;
	Area frameArea;
	int framex;
	int framey;
	int width;
	int height;
	
	int direction; //0 izquierda 1 derecha??
	bool turning;
	bool running;
public:	
	explicit Chell(const SdlWindow& window);
	~Chell();
	void renderCentered(int resx, int resy, float scale);	
	void render(int resx,int resy,int width,int height) override;	
	void idleAction();
	void jig();
	void jigAction();
	void run(int dir);
	void runAction();
	void stop(int dir);
	void stopAction();
	void turn(int dir);
	void turnAction();
	void jump();
	void jumpAction();
	void fall();
	void fallAction();
	void land();
	void landAction();
	void fire();
	void fireAction();
};

#endif
