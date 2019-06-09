#include "../include/playerLogin.h"
#include <unistd.h>
#include <iostream>

PlayerLogin::PlayerLogin(std::vector<Game*>& games,Socket peer): 
games(games),peer(std::move(peer)){}

void PlayerLogin::run(){
	std::cout<<"llego\n";
	this->games[0]->addPlayer(std::move(peer));
	usleep(100000000);
}
