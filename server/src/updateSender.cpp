#include "../include/updateSender.h"

UpdateSender::UpdateSender(Protocol& p,ProtectedQueue<Update>* updates) : running(true),protocol(p),
	updates(updates){}

UpdateSender::~UpdateSender(){}

void UpdateSender::run(){
	Update update;
	while(this->running){
		if(this->updates->try_pop(update)){
			this->protocol.sendUpdate(update);				
		}
		usleep(1000);
		
	}
}

void UpdateSender::stop(){
	this->running = false;
}
