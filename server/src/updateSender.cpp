#include "../include/updateSender.h"

UpdateSender::UpdateSender(Protocol& p) : running(true),protocol(p){}

UpdateSender::~UpdateSender(){}

void UpdateSender::run(){
	Update update;
	while(this->running){
		if(this->updates.try_pop(update)){
			this->protocol.sendUpdate(update);	
		}
		usleep(100000);
	}
}

void UpdateSender::stop(){
	this->running = false;
}

ProtectedQueue<Update>* UpdateSender::getQueuePtr(){
	return &this->updates;
}
