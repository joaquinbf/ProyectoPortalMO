#include "../include/accepter.h"

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

Accepter::~Accepter(){
    for(Game* game :  this->games){
        delete game;
    }
}

void Accepter::run() {
    this->games.push_back(new Game("MAPA.yaml"));
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            //ENVIAR AL PEER LISTA DE GAMES ABIERTO
            //ESPERAR PEER RESPONSE
            //PROCESAR COMANDO PARA CREAR PARTIDA O UNIR PEER A PARTIDA
            //ESTO HAY QUE HACERLO EN OTRO HILO PARA NO BLOQUEAR EL ACCEPTER
            this->games[0]->addPlayer(std::move(peer));
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
