#include "../include/updateReceiver.h"

UpdateReceiver::UpdateReceiver(const ServerManager& sm,ProtectedQueue<Update>& queue)
 : serverManager(sm), updates(queue), running(true) {} 

UpdateReceiver::~UpdateReceiver(){}

void UpdateReceiver::run(){
	Update update(CREATE_COMMAND,LASER,20,NONE_STATUS,200,200,0);
	this->updates.push(update);
	try{
		Update up;
		while(this->running){
			up = this->serverManager.receiveUpdate();
			this->updates.push(up);
		}
	}catch(const ConnectionErrorException &e){

	}
}

void UpdateReceiver::stop(){
	this->running = false;
}
