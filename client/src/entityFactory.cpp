#include "../include/entityFactory.h"
#include "../include/SdlWindow.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(CreatorMesage cm,const SdlWindow& window){
	switch(cm.getIdClass()){
		case CHELL:
			return new Chell(window); 
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}