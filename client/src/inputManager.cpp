#include "../include/inputManager.h"

#include "../../common/include/key.h"
#include "../../common/include/keypad.h"


InputManager::InputManager(const ServerManager& sm,GameView& v) : serverManager(sm),
gameView(v),running(true){
	this->chellId = this->gameView.getChellId();
}

InputManager::~InputManager(){}


void InputManager::stop(){
	this->running = false;
}

bool InputManager::isRunning() const{
	return this->running;
}

void InputManager::run(){
	Keypad keypad;

	SDL_Event event;
    while(this->running){
	    SDL_WaitEvent(&event);
	    switch(event.type) {
	        case SDL_KEYDOWN: {
	                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
							this->sendPressAction(
								keypad.getKey(KEY::LEFT_KEY),
								ACTION::RUN_LEFT);
	                        break;
	                    case SDLK_d:
							this->sendPressAction(
								keypad.getKey(KEY::RIGHT_KEY),
								ACTION::RUN_RIGHT);
	                        break;
	                    case SDLK_w:
							this->sendPressAction(
								keypad.getKey(KEY::UP_KEY),
								ACTION::JUMP);
	                        break;
	                    case SDLK_o:
	                    	this->gameView.zoomIn();
	                        break;
	                    case SDLK_p:
	                    	this->gameView.zoomOut();
	                        break;
                       case SDLK_n:
	                    	this->gameView.fullscreen();
	                        break;
	                    case SDLK_m:
	                    	this->gameView.windowed();
	                        break;
	                    case SDLK_b:
	                    	this->serverManager.sendAction(Action(this->chellId,ACTION::JIG,0));
	                    	break;
	                    case SDLK_SPACE:
	                    	this->serverManager.sendAction(Action(this->chellId,ACTION::FIRE,0));
	                    	break;
	                    }
	            } // Fin KEY_DOWN
	            break;
	        case SDL_KEYUP:{
	        	SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
	                switch (keyEvent.keysym.sym) {
	                    case SDLK_a:
	                    	this->sendReleaseAction(
								keypad.getKey(KEY::LEFT_KEY),
								ACTION::STOP_LEFT);
	                        break;
	                    case SDLK_d:
							this->sendReleaseAction(
								keypad.getKey(KEY::RIGHT_KEY),
								ACTION::STOP_RIGHT);
	                        break;
	                    case SDLK_w:
	                        break;
	                    case SDLK_s:
	                        break;
	                    }
	            } // Fin KEY_UP
	        	break;
	        case SDL_QUIT:
	        	this->serverManager.sendAction(Action(this->chellId,ACTION::QUIT,0));
	            this->running = false;
	            break;
	    }
    }
}

void InputManager::sendPressAction(Key *key, ACTION action) {
	if (!key->isBeingPressed()) {
		key->press();
		this->serverManager.sendAction(Action(this->chellId, action,0));
	}
}

void InputManager::sendReleaseAction(Key *key, ACTION action) {
	key->release();
	this->serverManager.sendAction(Action(this->chellId, action,0));
}
