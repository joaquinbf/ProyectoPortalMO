#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <thread>
#include <exception>
#include <list>

#include "../include/serverManager.h"
#include "../../common/include/creator.h"
#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/client.h"
#include "../include/background.h"

Client::Client() : serverManager("localhost","4545"){
	std::list<Creator> mylist = this->serverManager.createStage();
	for (Creator& c: mylist){
		std::cout<< c.getIdClass()<<std::endl;
		std::cout<< c.getIdObject()<<std::endl;
		std::cout<< c.getPosX()<<std::endl;
		std::cout<< c.getPosY()<<std::endl;
	}
}
Client::~Client(){}

int Client::main(){
	try {
        SdlWindow window(800, 600);
        window.fill();
        Chell chell(window);
        Background background(window);
        this->chellPtr = &chell;
        this->running = true;
       	this->x = 300;
        this->y = 280;
        std::thread inputManager([=]{this->inputManager();});
        while (this->running){
            window.fill(); // Repinto el fondo gris                       
            //lista de objetos dinamicos->dAW             render
            //lisyta objetos estaticos->render

            background.render(this->x-300,this->y-280,800,600);
            chell.render(Area(300,280,200,300));
            

            window.render();
            usleep(100000);
        }
        inputManager.join();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
	return 0;
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
	                    case SDLK_s:
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
