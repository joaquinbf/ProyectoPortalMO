#include "../include/client_manager.h"

ClientManager::ClientManager(const char *node):
    socket(RealSocketFactory::getServerSocket(node)) {
    this->socket.listen(100);
    this->peer = std::move(this->socket.accept());
}

void ClientManager::sendInt() {
    Protocolo protocolo(&this->peer);
    protocolo.sendUINT32(99);
}
