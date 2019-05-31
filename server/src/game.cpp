#include "../include/game.h"

Game::Game() : capacity(4){
	//aca tengo que cargar el mundo en updates
}

Game::~Game(){

}

void Game::addPlayer(Player player){
	//PRIMERO TENGO QUE ENVIARLE EL MUNDO AL JUGADOR EN FORMA DE UPDATES
	player.setInputPtr(&this->inputs);
	this->players.push_back(std::move(player));
}
