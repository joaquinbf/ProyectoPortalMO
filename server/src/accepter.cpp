#include "../include/accepter.h"
#include <iostream>
Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

Accepter::~Accepter(){
    for(Game* game :  this->games){
        delete game;
    }
    for(PlayerLogin* pl: this->logins){
        delete pl;
    }
}

void Accepter::run() {
    this->games.push_back(new Game("MAPA.yaml"));
    this->games.push_back(new Game("ASD.yaml"));
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            PlayerLogin* playerLogin = new PlayerLogin(&this->games,std::move(peer));
            playerLogin->start();
            playerLogin->detach();               
            this->logins.push_back(playerLogin);
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
