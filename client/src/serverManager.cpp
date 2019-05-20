#include "../include/serverManager.h"

ServerManager::ServerManager(const char* addres,const char * port){
	this->socket = Socket(addres,port);
}

ServerManager::~ServerManager(){}

void ServerManager::recvInt(){
	Protocolo protocol(&(this->socket));
	std::cout <<protocol.recvUINT32() << std::endl;
}
