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
			return new Block(tm,RECEIVER_BLOCK,update.getPosX(),update.getPosY(),200,200);
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
			break;
		case ENTITY::RECEIVER_BLOCK:
			return new Block(tm,RECEIVER_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;
		case ENTITY::ROCK:
			return new Rock(tm,update.getPosX(),update.getPosY(),100,100);
			break;
		case ENTITY::BUTTON:
			return new Button(tm,update.getStatus(),update.getPosX(),update.getPosY(),200,50);	
			break;
		case ENTITY::GATE:
			return new Gate(tm,update.getPosX(),update.getPosY(),200,400);
			break;
		case ENTITY::ACID:
			return new Acid(tm,update.getPosX(),update.getPosY(),200,60);
			break;
		case ENTITY::BULLET:
			return new Bullet(tm,update.getPosX(),update.getPosY(),100,60,update.getDirection()); 
			break;
		case ENTITY::LASER:
			return new Laser(tm,update.getPosX(),update.getPosY(),200,10,update.getDirection()); 
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}
