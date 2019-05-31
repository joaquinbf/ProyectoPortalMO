#include "../include/broadcaster.h"

Broadcaster::Broadcaster(ProtectedQueue<Update>* source):
running(true),source(source){}

Broadcaster::~Broadcaster(){}

void Broadcaster::addPlayer(ProtectedQueue<Update>* client){
	this->clients.push_back(client);
}

void Broadcaster::run(){
	Update update;
	while(this->running){
		if(this->source->try_pop(update)){
			for(ProtectedQueue<Update>* client : this->clients){
				client->push(update);
			}	
		}
		usleep(1000);
	}
}

void Broadcaster::stop(){
	this->running = false;
}