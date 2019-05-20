#include "../include/client_manager.h"

ClientManager::ClientManager(const char *node):
    socket(RealSocketFactory::getServerSocket(node)) {
    this->socket.listen(100);
}

void ClientManager::sendInt() {
    RealSocket peer = this->socket.accept();
    Protocolo protocolo(&peer);
    protocolo.sendUINT32(99);
}
