#include "../include/serverManager.h"

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

void ServerManager::createStage(){
	/*int total = this->protocol.recvQuad();
	while(total){
		creator = this->protocol.recvcreatror();
		client.create(creator);
		--total;	
	}	*/
}