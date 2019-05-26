#include "../include/entityFactory.h"
#include "../include/SdlWindow.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(const Update& update, const TextureManager& tm){
	switch(update.getIdClass()){
		case CHELL:
			return new Chell(tm,update.getPosX(),update.getPosY(),200,300,update.getDirection());
			break;
		case STONE_BLOCK:
			return new Block(tm,STONE_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;
		case METAL_BLOCK:
			return new Block(tm,METAL_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;	

		default:
			return nullptr;
			break;
	}
	return nullptr;
}
