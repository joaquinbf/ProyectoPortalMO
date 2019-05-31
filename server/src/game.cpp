#include "../include/game.h"

Game::Game(const std::string& mapName) : stage(mapName, &this->inputs,&this->updates),
	broadcaster(&this->updates){
	this->capacity = stage.getCapacity();
	this->stage.start();
	this->broadcaster.start();
}

Game::~Game(){	
	for(size_t i = 0;i < this->players.size() ;++i){
		delete this->players[i];	
	}
	this->stage.stop();
	this->stage.join();
	this->broadcaster.stop();
	this->broadcaster.join();
}

void Game::addPlayer(Socket socket){
	Player* player= new Player(std::move(socket));
	std::list<Update> ul = this->stage.getNewPlayerUpdates();
	player->sendChellIdToClient(this->players.size());
	player->setInputPtr(&this->inputs);
	for(Update u: ul){
		player->pushBackUpdate(u);
	}
	this->broadcaster.addPlayer(player->getUpdatesPtr());	
	player->start();	
	this->players.push_back(player);
}
