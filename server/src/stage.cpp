#include "../include/stage.h"

Stage::Stage(
	const std::string& mapName,
	ProtectedQueue<Action>* inputs,
	ProtectedQueue<Update>* updates):
	running(true),
	inputs(inputs),
	updates(updates) {
	Serializer serializer;
	serializer.deserialize(
		&this->world,
		MAP_PATH + mapName,
		"../config/config.yaml");
}

Stage::~Stage() {
}

bool Stage::validateMap() {
	return this->world.isValid();
}

void Stage::run() {
	GameLoop *game_loop = this->world.getGameLoop();

	while(this->running){
		game_loop->executeExternalInput(inputs);
		for (int i = 0; i < 6; i++) {
			game_loop->step();
			if (game_loop->isFinished()) {
				this->running = false;
				break;
			}
		}
		game_loop->fillUpdates(updates);
		usleep(50000);
	}
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

bool Stage::isChellAlive(uint32_t id) const{
	return this->world.isChellAlive(id);
}
