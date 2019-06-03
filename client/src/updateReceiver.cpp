#include "../include/updateReceiver.h"

UpdateReceiver::UpdateReceiver(const ServerManager& sm,ProtectedQueue<Update>& queue)
 : serverManager(sm), updates(queue), running(true) {} 

UpdateReceiver::~UpdateReceiver(){}

void UpdateReceiver::run(){
	for(int i = 0;i<10;++i){
		Update update(CREATE_COMMAND,ROCK,20+i,NONE_STATUS,100*i,200,2);
		this->updates.push(update);
	}
	
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