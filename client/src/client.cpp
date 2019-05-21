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

Client::Client(int x, int y) 
: resx(x),resy(y), scale(1),serverManager("localhost","4545"){
	std::list<Creator> mylist = this->serverManager.createStage();
	for (Creator& c: mylist){
		c.getIdClass();
		//do something
	}
}

Client::~Client(){}

int Client::main(){
	try {
        SdlWindow window(this->resx, this->resy);
        window.fill();
        Chell chell(window);
        Background background(window);
        this->running = true;
        std::thread inputManager([=]{this->inputManager();});
        while (this->running){
            window.fill(); // Repinto el fondo gris                       
            //lista de objetos dinamicos->render
            //lista objetos estaticos->render

            background.render(0,0,this->resx,this->resy);
            
            int a=(this->resx/2)-((200/2)*this->scale);
            int b=(7*this->resy/8)-(300*this->scale);
            chell.render(Area(a,b,200*this->scale,300*this->scale));
            

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
	                    case SDLK_o:
	                    	this->scale += 0.1;
	                        break;
	                    case SDLK_p:
	                    	this->scale -= 0.1;
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
