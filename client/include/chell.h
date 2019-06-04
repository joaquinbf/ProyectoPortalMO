#ifndef _CHELL_H_
#define _CHELL_H_

#include <iostream>

#include "../include/textureManager.h"
#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../../common/include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

#define IDLE_TEXTURE "../resources/textures/chell/resting-idle.png"
#define JIG_TEXTURE "../resources/textures/chell/jig.png"
#define RUNNING_TEXTURE "../resources/textures/chell/running.png"
#define STOPING_TEXTURE "../resources/textures/chell/stoping.png"
#define TURN_TEXTURE "../resources/textures/chell/turn.png"
#define JUMP_RISE_TEXTURE "../resources/textures/chell/jump-rise.png"
#define JUMP_APEX_TEXTURE "../resources/textures/chell/jump-apex.png"
#define JUMP_FALL_TEXTURE "../resources/textures/chell/jump-fall.png"
#define JUMP_LAND_TEXTURE "../resources/textures/chell/jump-land.png"
#define FIRE_TEXTURE "../resources/textures/chell/fire.png"
#define FIRE_TO_IDLE_TEXTURE "../resources/textures/chell/fire-to-idle.png"

class Chell : public Entity{
private:
	SdlTexture * texturePtr;
	void(Chell::* actionPtr)();
	const TextureManager & textureManager;
	Area frameArea;
	int frame;
	int framey;

	STATUS status;

public:	
	explicit Chell(const TextureManager& tm,int32_t posx,int32_t posy,
		uint32_t width,uint32_t height,uint32_t dir);
	~Chell();
	int32_t getPosX();
	int32_t getPosY();
	void renderCentered(int resx, int resy, float scale);	
	void step() override;
	void render(int resx,int resy,int width,int height,float scale) override;
	void update(const Update& update) override;	
	void idle();
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
	void fall(int dir);
	void fallAction();
	void land();
	void landAction();
	void fire(int dir);
	void fireAction();
};

#endif
