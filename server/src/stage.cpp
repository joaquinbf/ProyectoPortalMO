#include "../include/stage.h"
#include <iostream>
#include <string>

Stage::Stage(
	const std::string& mapName,
	ProtectedQueue<Action>* inputs,
	ProtectedQueue<Update>* updates):
	running(true),
	inputs(inputs),
	updates(updates) {
	Serializer serializer;

	this->world.createChell(1.65469, 10.1902);
	this->world.createChell(1.65469, 10.1902);
	this->world.createChell(1.65469, 10.1902);
	this->world.createChell(1.65469, 10.1902);
	serializer.deserialize(&this->world, "../maps/test_00.ptl");
}

Stage::~Stage(){}

void Stage::run() {
	while(this->running){
		this->world.addExternalInput(inputs);
		this->world.bigStep();
		this->world.fillUpdates(updates);
		usleep(50000);
	}
}

void Stage::stop(){
	this->running = false;
}

std::list<uint32_t> Stage::getChellsIdList() const{
	return this->world.getChellsIdList();
}

std::list<Update> Stage::getNewPlayerUpdates() const {
	return this->world.getNewPlayerUpdates();
}
