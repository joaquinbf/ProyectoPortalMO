#include "../include/inputManager.h"

InputManager::InputManager(const ServerManager& sm) : serverManager(sm),running(true){
}

InputManager::~InputManager(){}


void InputManager::stop(){
	this->running = false;
}

bool InputManager::isRunning() const{
	return this->running;
}

void InputManager::run(){
	SDL_Event event;
    while(this->running){
	    SDL_WaitEvent(&event);
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
	                    	//this->zoomIn();
	                        break;
	                    case SDLK_p:
	                    	//this->zoomOut();
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
