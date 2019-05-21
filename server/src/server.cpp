#include "../include/server.h"

Server::Server() {
    this->socket.bindAndListen(PORT);
}


int Server::main() {
    Accepter accepter(&this->socket);
    return 0;
}
