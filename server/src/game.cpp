#include "../include/game.h"

uint32_t Game::number = 0;

Game::Game(const std::string& mapName) : stage(mapName, &this->inputs,&this->updates),
	broadcaster(&this->updates),gameInfo(this->number,mapName,0,0){	
	this->chellsIds = this->stage.getChellsIdList();
	this->gameInfo.setCapacity(this->chellsIds.size());
	this->stage.start();
	this->broadcaster.start();
	++this->number;
}

Game::~Game(){	
	for(auto player : this->players){
		delete player.second;
	}
	this->stage.stop();
	this->stage.join();
	this->broadcaster.stop();
	this->broadcaster.join();
}

void Game::addPlayer(Player* player){
	std::list<Update> ul = this->stage.getNewPlayerUpdates();
	uint32_t id = this->chellsIds.back();
	player->sendChellIdToClient(id);
	this->chellsIds.pop_back();

	player->setInputPtr(&this->inputs);
	for(Update u: ul){
		player->pushBackUpdate(u);
	}
	this->broadcaster.addPlayer(player->getUpdatesPtr(),id);	
	player->start();	
	this->players[id] = player;
	this->gameInfo.addPlayer();
}

const GameInfo& Game::getGameInfo(){
	return this->gameInfo;
}

uint32_t Game::getId() const{
	return this->gameInfo.getId();
}

void Game::stop(){
	for(auto player : this->players){
		player.second->stop();
	}
	this->stage.stop();
	this->stage.join();
	this->broadcaster.stop();
	this->broadcaster.join();
}