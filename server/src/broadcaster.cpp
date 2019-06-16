#include "../include/broadcaster.h"

Broadcaster::Broadcaster(ProtectedQueue<Update>* source):
running(true),source(source){}

Broadcaster::~Broadcaster(){}

void Broadcaster::addPlayer(ProtectedQueue<Update>* client,uint32_t id){
	this->clients[id]=client;
}

void Broadcaster::run(){
	Update update;
	while(this->running){
		if(this->source->try_pop(update)){
			for(auto client : this->clients){
				client.second->push(update);
			}	
		}
		usleep(1000);
	}
}

void Broadcaster::stop(){
	this->running = false;
}