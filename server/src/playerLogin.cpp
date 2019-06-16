#include "../include/playerLogin.h"

PlayerLogin::PlayerLogin(std::list<Game*>* games,Socket peer): 
games(games),peer(std::move(peer)){}

void PlayerLogin::run(){
	Player* player = new Player(std::move(this->peer));
	
	player->sendGamesList(this->games);
	player->sendMapList();

	uint8_t byte = player->receiveByte();
	
	if(byte == 1){
		uint32_t gameId = player->receiveQuad();
		for(Game* game: *(this->games)){
			if(game->getId() == gameId){
				player->setDisconnecterPtr(game->getDisconnecterPtr());
				game->addPlayer(player);
				return;
			}
		}
	}else if (byte == 0){
		std::string mapName = player->receiveLine();
		mapName += ".yaml";
		Game * game = new Game(mapName);
		player->setDisconnecterPtr(game->getDisconnecterPtr());
		game->addPlayer(player);
		this->games->push_back(game);
		return;
	}else{
		return;
	}
}
