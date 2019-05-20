#include "../include/clientManager.h"

ClientManager::ClientManager(Socket socket) 
: protocol(std::move(socket)){}

ClientManager::~ClientManager(){}

void ClientManager::sendInt(uint32_t number){
	this->protocol.sendQuad(number);
}