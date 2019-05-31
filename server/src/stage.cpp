#include "../include/stage.h"

Stage::Stage(const std::string& mapName,
	ProtectedQueue<Action>* inputs,ProtectedQueue<Update>* updates) :
inputs(inputs),updates(updates)
{

}

Stage::~Stage(){

}

uint32_t Stage::getCapacity() const{
	return 4; //HARDCODED
}

std::list<Update> Stage::getNewPlayerUpdates() const{
	std::list<Update> list;
	return list;
}