#include "../include/accepter.h"
#include <iostream>

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    std::cout << "Accepter::run()" << std::endl;
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            this->world.addPlayer(std::move(peer));
        }
    } catch (const ConnectionErrorException &e) {
    }

}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.shutdown('f');
    this->socket.close();
}
