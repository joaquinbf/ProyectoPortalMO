#include "../include/accepter.h"
#include "../../common/include/exceptions.h"

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    this->keep_running = true;
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            Socket *ptr = &peer;
            ptr++;
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
