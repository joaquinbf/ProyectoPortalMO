#include "../include/serverManager.h"

ServerManager::ServerManager(const char* address,const char * port){
	Socket skt;
	skt.connect(std::string(address),std::string(port));
	Protocol prt(std::move(skt));
	this->protocol = std::move(prt);
}

ServerManager::~ServerManager(){}

void ServerManager::sendAction(const Action ac) const{
	this->protocol.sendAction(ac);
}

void ServerManager::stop(){
	this->protocol.close();
}

Update ServerManager::receiveUpdate() const{
	return this->protocol.receiveUpdate();
}

uint32_t ServerManager::receiveChellId() const{
	return this->protocol.receiveQuad();
}
