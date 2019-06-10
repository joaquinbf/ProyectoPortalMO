#include "../include/stage.h"
#include <iostream>

Stage::Stage(const std::string& mapName,
	ProtectedQueue<Action>* inputs,ProtectedQueue<Update>* updates) :
running(true),inputs(inputs),updates(updates)
{
	this->world.createWorldOne();
}

Stage::~Stage(){}

void Stage::run() {
	// world.setInputs(inputs)
	// world.setUpdates(updates)
	// while (this->running) {
	// 	world.gameLoop()
	// 	usleep(50000)
	// }
	//
	// Action action;
	// std::list<Update> list;
	while(this->running){
		this->world.addExternalInput(inputs);
		this->world.bigStep();
		this->world.fillUpdates(updates);
		usleep(50000);

		// while(this->inputs->try_pop(action)){
		// 	if(this->running){
		// 		this->world.applyAction(action);
		// 	}
		// }
		//
		// if(this->running){
		// 	this->world.applyStateActions();
		// }
		//
		// if(this->running){
		// 	this->world.step();
		// }
		//
		// if(this->running){
		// 	list = world.getBodyUpdates();
		// }
		//
		// if(this->running){
		// 	world.deleteBodiesForDeletion();
		// }
		//
		// for(Update update : list){
		// 	if(this->running){
		// 		this->updates->push(update);
		// 	}
		// }
		// list = world.getPinUpdateList();
		// for(Update update : list){
		// 	this->updates->push(update);
		// }
		//
		// if(this->running){
		// 	usleep(50000);
		// }
	}
}

void Stage::stop(){
	this->running = false;
}

uint32_t Stage::getCapacity() const{
	return 4; //HARDCODED
}

std::list<Update> Stage::getNewPlayerUpdates() const {
	return this->world.getNewPlayerUpdates();
}
