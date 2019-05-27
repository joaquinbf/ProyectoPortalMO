#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <thread>
#include <exception>
#include <list>

#include "../include/entityFactory.h"
#include "../include/serverManager.h"
#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/client.h"
#include "../include/background.h"

#include "../../common/include/port.h"

Client::Client(int x, int y)
: resx(x),resy(y),window(x,y),myChell(nullptr), scale(1),
textureManager(window),serverManager("localhost", PORT){
	//myChellId = this->serverManager.GetChellId();
	//FALTA RECIBIR CHELL ID
	myChellId = 0;
}

Client::~Client(){
	if(this->myChell != nullptr){
		delete this->myChell;
	}
	for( auto it = this->entities.begin(); it != this->entities.end(); ++it ){
		if(it->second != nullptr){
			delete it->second;
		}
	}
}

void Client::main(){
    this->running = true;
    Update update;
    std::thread inputManager([=]{this->inputManager();});
    std::thread updateReceiver([=]{this->updateReceiver();});

    while (this->running){
		/*PROCESO UPDATES*/
		while(this->updates.try_pop(update)){
			this->updateHandler(update);
		}
		/*RENDER*/
        this->window.fill(); // Repinto el fondo gris
    	for( auto it = this->entities.begin(); it != this->entities.end(); ++it ){
			it->second->render(this->myChell->getPosX(),this->myChell->getPosY(),
				this->resx,this->resy,this->scale);
		}
		if(myChell != nullptr){
			this->myChell->renderCentered(this->resx,this->resy,this->scale);	
		}
        
        this->window.render();

        usleep(100000);
    }
    this->serverManager.stop();
    inputManager.join();
    updateReceiver.join();
}

void Client::updateReceiver(){
	try{
		Update up;
		while(this->running){
			up = this->serverManager.receiveUpdate();
			this->updates.push(up);
		}
	}catch(const ConnectionErrorException &e){

	}
}

void Client::inputManager(){
	SDL_Event event;
    while(this->running){
	    if(SDL_PollEvent(&event) != 0){
	    switch(event.type) {
	        case SDL_KEYDOWN: {
	                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                        this->serverManager.sendAction(Action(ACTION::RUN_LEFT,0));
	                        break;
	                    case SDLK_d:
	                        this->serverManager.sendAction(Action(ACTION::RUN_RIGHT,0));
	                        break;
	                    case SDLK_w:
	                    	this->serverManager.sendAction(Action(ACTION::JUMP,0));
	                        break;
	                    case SDLK_o:
	                    	this->zoomIn();
	                        break;
	                    case SDLK_p:
	                    	this->zoomOut();
	                        break;
	                    case SDLK_b:
	                    	this->serverManager.sendAction(Action(ACTION::JIG,0));
	                    	break;
	                    case SDLK_SPACE:
	                    	this->serverManager.sendAction(Action(ACTION::FIRE,0));
	                    	break;
	                    }
	            } // Fin KEY_DOWN
	            break;
	        case SDL_KEYUP:{
	        	SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                    	this->serverManager.sendAction(Action(ACTION::STOP_LEFT,0));
	                        break;
	                    case SDLK_d:
	                    	this->serverManager.sendAction(Action(ACTION::STOP_RIGHT,0));
	                        break;
	                    case SDLK_w:
	                        break;
	                    case SDLK_s:
	                        break;
	                    }
	            } // Fin KEY_UP
	        	break;
	        case SDL_QUIT:
	        	this->serverManager.sendAction(Action(ACTION::QUIT,0));
	            this->running = false;
	            break;
	    }
	    }
    }
}

void Client::updateHandler(Update update){
	EntityFactory ef;
	uint32_t id;
	switch(update.getCommand()){
		case COMMAND::CREATE_COMMAND:
			
			id = update.getIdObject();
			if(id == this->myChellId){ 
				this->myChell=(Chell *)ef.create(update,this->textureManager);
			} else {
				this->entities[id] = ef.create(update,this->textureManager);
			}
			break;
		case COMMAND::UPDATE_COMMAND:
			id = update.getIdObject();
			if(id == this->myChellId){
				this->myChell->update(update);
			}else{
				this->entities[id]->update(update);
			}
			break;
		case COMMAND::DESTROY_COMMAND:
			//FALTA IMPLEMENTAR
			break;
		default:
			break;
	}
}

void Client::zoomIn(){
	if(this->scale < 1){
		this->scale+=0.05;
	}
}

void Client::zoomOut(){
	if(this->scale > 0.5){
		this->scale-=0.05;
	}
}
