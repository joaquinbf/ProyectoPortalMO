#include "../include/playerLogin.h"
#include <iostream>

PlayerLogin::PlayerLogin(std::list<Game*>* games,Socket peer): 
games(games),peer(std::move(peer)){}

void PlayerLogin::run(){
	Player* player = new Player(std::move(this->peer));
	player->sendGamesList(this->games);

	auto it = this->games->begin();
	(*it)->addPlayer(player);
}
