#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <thread>
#include <exception>
#include <list>

#include "../../common/include/creatorMesage.h"
#include "../include/entityFactory.h"
#include "../include/serverManager.h"
#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/client.h"
#include "../include/background.h"

Client::Client(int x, int y) 
: resx(x),resy(y),window(x,y), scale(1),serverManager("localhost","4545"){
	std::list<CreatorMesage> mylist = this->serverManager.createStage();
	EntityFactory ef;
	for (CreatorMesage& c: mylist){
		this->entities[c.getIdObject()]=ef.create(c,this->window);
		//do something
	}
}

Client::~Client(){}

void Client::main(){
    this->window.fill();
    Chell myChell(this->window);

    this->running = true;
    std::thread inputManager([=]{this->inputManager();});
    while (this->running){
 
        this->window.fill(); // Repinto el fondo gris                       
        myChell.renderCentered(this->resx,this->resy,this->scale);
        //lista de objetos->render        
        this->window.render();
        usleep(100000);
    }
    inputManager.join();
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
	                        this->serverManager.sendAction(Action(RUN_LEFT,0));
	                        break;
	                    case SDLK_d:
	                        this->serverManager.sendAction(Action(RUN_RIGHT,0));
	                        break;
	                    case SDLK_w:                    
	                    	this->serverManager.sendAction(Action(JUMP,0));
	                        break;
	                    case SDLK_o:
	                    	this->zoomIn();
	                        break;
	                    case SDLK_p:
	                    	this->zoomOut();
	                        break;
	                    case SDLK_b:
	                    	this->serverManager.sendAction(Action(JIG,0));
	                    	break;
	                    case SDLK_SPACE:
	                    	this->serverManager.sendAction(Action(FIRE,0));
	                    	break;
	                    }
	            } // Fin KEY_DOWN
	            break;
	        case SDL_KEYUP:{
	        	SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                    	this->serverManager.sendAction(Action(STOP_LEFT,0));
	                        break;
	                    case SDLK_d:
	                    	this->serverManager.sendAction(Action(STOP_RIGHT,0));
	                        break;
	                    case SDLK_w:
	                        break;
	                    case SDLK_s:
	                        break;
	                    }
	            } // Fin KEY_UP
	        	break;
	        case SDL_QUIT:
	            this->running = false;
	            break;
	    }
	    }	
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
