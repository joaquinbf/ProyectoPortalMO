#include <list>

#include "../include/serverManager.h"
#include "../../common/include/creator.h"


ServerManager::ServerManager(const char* address,const char * port){
	Socket skt;
	skt.connect(std::string(address),std::string(port));
	Protocol prt(std::move(skt));
	this->protocol = std::move(prt);
}

ServerManager::~ServerManager(){}

void ServerManager::recvInt(){
	std::cout << this->protocol.receiveQuad() << std::endl;
}

std::list<Creator> ServerManager::createStage(){
	std::list<Creator> list;
	int total = this->protocol.receiveQuad();
	while(total){
		Creator creator = this->protocol.receiveCreator();
		list.push_back(creator);
		--total;	
	}	
	return list;
}
