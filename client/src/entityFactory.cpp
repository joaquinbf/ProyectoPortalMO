#include "../include/entityFactory.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(const Update& update, const TextureManager& tm){
	Block* ptr;
	switch(update.getIdClass()){
		case ENTITY::CHELL:
			return new Chell(tm,update.getPosX(),update.getPosY(),200,300,update.getDirection());
			break;
		case ENTITY::STONE_BLOCK:
			return new Block(tm,STONE_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;
		case ENTITY::METAL_BLOCK:
			return new Block(tm,METAL_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;	
		case ENTITY::METAL_TRIAG_BLOCK:
			ptr = new Block(tm,METAL_TRIAG_BLOCK,update.getPosX(),update.getPosY(),200,200);
			ptr->setDirection(update.getDirection());
			return (Entity *) ptr;
			break;
		case ENTITY::LAUNCH_BLOCK:
			ptr = new Block(tm,LAUNCH_BLOCK,update.getPosX(),update.getPosY(),200,200);
			ptr->setDirection(update.getDirection());
			return (Entity *) ptr;
		case ENTITY::ROCK:
			return nullptr;
			break;
		case ENTITY::BUTTON:
			return new Button(tm,update.getStatus(),update.getPosX(),update.getPosY(),200,50);	
			break;
		case ENTITY::GATE:
			return nullptr;
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}
