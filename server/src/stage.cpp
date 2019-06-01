#include "../include/stage.h"

Stage::Stage(const std::string& mapName,
	ProtectedQueue<Action>* inputs,ProtectedQueue<Update>* updates) :
running(true),inputs(inputs),updates(updates)
{

}

Stage::~Stage(){}

void Stage::run(){
	Action action;
	std::list<Update> list;
	while(this->running){
		while(this->inputs->try_pop(action)){
			//this->world.aplyAction(action);
		}
		//this->world.step();
		//list = world.getUpdates();
		for(Update update : list){
			this->updates->push(update);
		}
		usleep(100000);
	}
}

void Stage::stop(){
	this->running = false;
}

uint32_t Stage::getCapacity() const{
	return 4; //HARDCODED
}

std::list<Update> Stage::getNewPlayerUpdates() const{
	std::list<Update> list;
	return list;
	//return this->world.getNewPlayerUpdates();
}