#include "../include/entityFactory.h"
#include "../include/SdlWindow.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(CreatorMessage cm, const TextureManager& tm){
	switch(cm.getIdClass()){
		case CHELL:
			return new Chell(tm,cm.getPosX(),cm.getPosY(),200,300,cm.getDir());
			break;
		case STONE_BLOCK:
			return new Block(tm,STONE_BLOCK,cm.getPosX(),cm.getPosY(),200,200);
			break;
		case METAL_BLOCK:
			return new Block(tm,METAL_BLOCK,cm.getPosX(),cm.getPosY(),200,200);
			break;	

		default:
			return nullptr;
			break;
	}
	return nullptr;
}
