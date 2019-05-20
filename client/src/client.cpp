#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <thread>
#include <exception>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/client.h"
#include "../include/background.h"

Client::Client(){}
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
        std::thread inputManager([=]{this->eventManager();});
        while (this->running){
            window.fill(); // Repinto el fondo gris                       
            //lista de objetos dinamicos->render
            //lista objetos estaticos->render

            background.render(this->x-300,this->y-280,800,600);
            chell.render(Area(300,280,200,300));
            

            window.render();
            usleep(100000);
        }
        inputManager.stop();
        inputManager.join();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
	return 0;
}

void Client::eventManager(){	
	SDL_Event event;
    while(this->running){
	    if(SDL_PollEvent(&event) != 0){
	    switch(event.type) {
	        case SDL_KEYDOWN: {
	                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                        this->chellPtr->run(0);
	                        this->x -= 10;
	                        break;
	                    case SDLK_d:
	                        this->chellPtr->run(1);
	                        this->x += 10;
	                        break;
	                    case SDLK_w:                    
	                    	this->chellPtr->jump();
	                        this->y -= 10;
	                        break;
	                    case SDLK_s:
	                    	this->chellPtr->fall();
	                        this->y += 10;
	                        break;
	                    case SDLK_b:
	                    	this->chellPtr->jig();
	                    	break;
	                    case SDLK_SPACE:
	                    	this->chellPtr->fire();
	                    	break;
	                    }
	            } // Fin KEY_DOWN
	            break;
	        case SDL_KEYUP:{
	        	SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                    	this->chellPtr->stop(0);
	                        this->x -= 5;
	                        break;
	                    case SDLK_d:
	                    	this->chellPtr->stop(1);
	                        this->x += 5;
	                        break;
	                    case SDLK_w:
	                        this->y -= 5;
	                        break;
	                    case SDLK_s:
	                        this->y += 5;
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
