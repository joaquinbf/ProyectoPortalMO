#include <iostream>
#include "../include/serverManager.h"

ServerManager::ServerManager(const char * adress, const char * port){
	RealSocketFactory rsf();
	this->socket = rsf.getClientSocket(adress,port);
	this->protocol = Protocol(&(this->socket));
}

void serverManager::recvInt(){
	uint32_t i = this->protocol.recvUINT32();
	std::cout<<"RECIBI: "<<i<"\n";
}