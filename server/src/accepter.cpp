#include "../include/accepter.h"

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    this->games.push_back(new Game());
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            //SEND PEER LIST OF GAMES
            //WAIT FOR PEER RESPONSE
            //PROCESAR COMANDO PARA CREAR PARTIDA O UNIR PEER A PARTIDA
            //ESTO HAY QUE HACERLO EN OTRO HILO PARA NO BLOQUEAR EL ACCEPTER
            this->games[0]->addPlayer(std::move(peer));
        }
    } catch (const ConnectionErrorException &e) {
    }
    //this->match.stop();
    //this->match.join();
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
