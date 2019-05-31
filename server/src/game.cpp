#include "../include/game.h"

Game::Game() : capacity(4){
	//aca tengo que cargar el mundo desde el archivo
}

Game::~Game(){	
	for(size_t i = 0;i < this->players.size() ;++i){
		this->players[i]->stop();	
	}
}

void Game::addPlayer(Socket socket){
	//PRIMERO TENGO QUE ENVIARLE EL MUNDO AL JUGADOR EN FORMA DE UPDATES
	Player* player= new Player(std::move(socket));
	player->setInputPtr(&this->inputs);
	player->start();
	this->players.push_back(player);
}
