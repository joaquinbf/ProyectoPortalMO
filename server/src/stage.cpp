#include "../include/stage.h"

Stage::Stage(
	const std::string& mapName,
	ProtectedQueue<Action>* inputs,
	ProtectedQueue<Update>* updates):
	running(true),
	inputs(inputs),
	updates(updates) {
	Serializer serializer;
	serializer.deserialize(&this->world, MAP_PATH + mapName);
}

Stage::~Stage(){}

bool Stage::validateMap() {
	return this->world.isValid();
}

void Stage::run() {
	while(this->running){
		this->world.addExternalInput(inputs);
		this->world.bigStep();
		if(this->world.isFinished()){
			this->running = false;
		}
		this->world.fillUpdates(updates);
		usleep(50000);
	}

	// GameLoop *game_loop = this->world.getGameLoop();
	// while(this->running){
	// 	game_loop->executeExternalInput(inputs);
	// 	game_loop->step();
	// 	if (this->world.isFinished()) {
	// 		this->running = false;
	// 	}
	// 	game_loop->fillUpdates(updates);
	// 	usleep(50000);
	// }
}

void Stage::stop(){
	this->running = false;
}

bool Stage::isRunning(){
	return this->running;
}

std::list<uint32_t> Stage::getChellsIdList() const{
	return this->world.getChellsIdList();
}

std::list<Update> Stage::getNewPlayerUpdates() const {
	return this->world.getNewPlayerUpdates();
}
