#include <list>

#include "../include/serverManager.h"

ServerManager::ServerManager(const char* address,const char * port){
	Socket skt;
	skt.connect(std::string(address),std::string(port));
	Protocol prt(std::move(skt));
	this->protocol = std::move(prt);
}

ServerManager::~ServerManager(){}

void ServerManager::stop(){
	this->protocol.close();
}


std::list<CreatorMessage> ServerManager::receiveStage(){
	std::list<CreatorMessage> list;
	uint32_t total = this->protocol.receiveQuad();	
	while(total){
		CreatorMessage creator = this->protocol.receiveCreator();
		list.push_back(creator);
		--total;
	}
	return list;
}

void ServerManager::sendAction(const Action ac){
	this->protocol.sendAction(ac);
}

Update ServerManager::receiveUpdate(){
	return this->protocol.receiveUpdate();
}
