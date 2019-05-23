#include "../include/entityFactory.h"
#include "../include/SdlWindow.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(CreatorMesage cm,const SdlWindow& window){
	switch(cm.getIdClass()){
		case 0:
			return new Chell(window); 
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}