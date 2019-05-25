#include "../include/textureManager.h"

TextureManager::TextureManager(const SdlWindow& window):
/*idleTexture(CHELL_IDLE_TEXTURE,window), 
jigTexture(CHELL_JIG_TEXTURE,window), 
runTexture(CHELL_RUNNING_TEXTURE,window), 
stopTexture(CHELL_STOPING_TEXTURE,window),
turnTexture(CHELL_TURN_TEXTURE,window), 
jumpRiseTexture(CHELL_JUMP_RISE_TEXTURE,window),
jumpApexTexture(CHELL_JUMP_APEX_TEXTURE,window), 
jumpFallTexture(CHELL_JUMP_FALL_TEXTURE,window),
jumpLandTexture(CHELL_JUMP_LAND_TEXTURE,window), 
fireTexture(CHELL_FIRE_TEXTURE,window),
fireToIdleTexture(CHELL_FIRE_TO_IDLE_TEXTURE,window),*/
metalBlockTexture(METAL_BLOCK_TEXTURE,window),
metalTriagBlockTexture(METAL_TRIAG_BLOCK_TEXTURE,window),
stoneBlockTexture(STONE_BLOCK_TEXTURE,window),
launchBlockTexture(LAUNCH_BLOCK_TEXTURE,window)
	{}

TextureManager::~TextureManager(){}
	
SdlTexture * TextureManager::getBlockTexturePointer(const ENTITY e){
	switch(e){
		case STONE_BLOCK:
			return &(this->stoneBlockTexture);
			break;
		case METAL_BLOCK:
			return &(this->metalBlockTexture);
			break;
		case METAL_TRIAG_BLOCK:
			return &(this->metalTriagBlockTexture);
			break;
		case LAUNCH_BLOCK:
			return &(this->launchBlockTexture);
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}
