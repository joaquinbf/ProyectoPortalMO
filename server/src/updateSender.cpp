#include "../include/updateSender.h"
#include <iostream>

UpdateSender::UpdateSender(Protocol& p,ProtectedQueue<Update>* updates) : running(true),protocol(p),
	updates(updates){}

UpdateSender::~UpdateSender(){}

void UpdateSender::run(){
	Update update;
	while(this->running){
		/*if(this->updates->try_pop(update)){
			this->protocol.sendUpdate(update);				
		}
		usleep(1000);*/
		update = this->updates->wait_and_pop();
		if(this->protocol.isConnected() && this->running){
			this->protocol.sendUpdate(update);	
		}
		
					
	}
	std::cout<<"LLEGO HASTA ACA\n";
}

void UpdateSender::stop(){
	this->running = false;
	this->updates->push(Update());
	std::cout<<"CIERRO\n";
}
