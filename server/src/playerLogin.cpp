#include "../include/playerLogin.h"

PlayerLogin::PlayerLogin(std::map<uint32_t,Game*>* games,Socket peer): 
joinable(false),games(games),peer(std::move(peer)){}

void PlayerLogin::run(){
	Player* player = new Player(std::move(this->peer));
	
	player->sendGamesList(this->games);
	player->sendMapList();

	uint8_t byte = player->receiveByte();
	
	if(byte == 1){
		uint32_t gameId = player->receiveQuad();
		for(auto it: *(this->games)){
			if(it.first == gameId){
				player->setDisconnecterPtr(it.second->getDisconnecterPtr());
				player->sendByte(0);
				it.second->addPlayer(player);				
				this->joinable = true;
				return;				
			}
		}
	}else if (byte == 0){
		std::string mapName = player->receiveLine();
		mapName += ".yaml";
		Game * game = new Game(mapName);
		if(!game->isFinished()){
			player->sendByte(0);
			player->setDisconnecterPtr(game->getDisconnecterPtr());
			game->addPlayer(player);
			(*this->games)[game->getId()] = game;
			this->joinable = true;
			return;
		} else {
			player->sendByte(1);
			this->joinable = true;
			return;	
		}
	}else{
		player->sendByte(1);
		this->joinable = true;
		return;
	}
}

bool PlayerLogin::isJoinable(){
	return this->joinable;
}
