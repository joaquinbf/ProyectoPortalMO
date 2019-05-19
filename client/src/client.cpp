#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <thread>
#include <exception>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/client.h"

Client::Client(){}
Client::~Client(){}

int Client::main(){
	try {
        SdlWindow window(800, 600);
        window.fill();
        Chell chell(window);
        this->chellPtr = &chell;
        this->running = true;
       	this->x = 100;
        this->y = 150;
        std::thread inputManager([=]{this->eventManager();});
        while (this->running){
            window.fill(); // Repinto el fondo gris
            chell.render(Area(this->x,this->y,104,215));
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

void Client::eventManager(){	
	SDL_Event event;
// Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while(this->running){
    //SDL_WaitEvent(&event);
    if(SDL_PollEvent(&event) != 0){
    switch(event.type) {
        case SDL_KEYDOWN: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        this->x -= 10;
                        break;
                    case SDLK_RIGHT:
                        this->chellPtr->runRightAction();
                        this->x += 10;
                        break;
                    case SDLK_UP:
                        this->y -= 10;
                        break;
                    case SDLK_DOWN:
                        this->y += 10;
                        break;
                    case SDLK_b:
                    	this->chellPtr->jigAction();
                    	break;
                    }
            } // Fin KEY_DOWN
            break;
        case SDL_KEYUP:{
        	SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        this->x -= 5;
                        break;
                    case SDLK_RIGHT:
                    	this->chellPtr->stopRightAction();
                        this->x += 5;
                        break;
                    case SDLK_UP:
                        this->y -= 5;
                        break;
                    case SDLK_DOWN:
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
