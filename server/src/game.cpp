#include "../include/game.h"

uint32_t Game::number = 0;

Game::Game(const std::string& mapName) : stage(mapName, &this->inputs,&this->updates),
	broadcaster(&this->updates),gameInfo(this->number,mapName,0,0){
	this->gameInfo.setCapacity(stage.getCapacity());
	this->stage.start();
	this->broadcaster.start();
	++this->number;
}

Game::~Game(){	
	for(Player* player : this->players){
		delete player;
	}
	this->stage.stop();
	this->stage.join();
	this->broadcaster.stop();
	this->broadcaster.join();
}

void Game::addPlayer(Player* player){
	std::list<Update> ul = this->stage.getNewPlayerUpdates();
	player->sendChellIdToClient(this->players.size());
	player->setInputPtr(&this->inputs);
	for(Update u: ul){
		player->pushBackUpdate(u);
	}
	this->broadcaster.addPlayer(player->getUpdatesPtr());	
	player->start();	
	this->players.push_back(player);
	this->gameInfo.addPlayer();
}

const GameInfo& Game::getGameInfo(){
	return this->gameInfo;
}

uint32_t Game::getId() const{
	return this->gameInfo.getId();
}