#include "../include/inputManager.h"

InputManager::InputManager(const ServerManager& sm,GameView& v) : serverManager(sm),
chellId(0),gameView(v),running(true){
	
}

InputManager::~InputManager(){}


void InputManager::stop(){
	this->running = false;
}

bool InputManager::isRunning() const{
	return this->running;
}

void InputManager::run(){
	this->chellId = this->gameView.getChellId();
    SDL_Event event;
    while(this->running){
    	SDL_WaitEvent(&event);
    	if(this->gameView.isPaused()){
    		this->pauseMode(event);
    	} else {
    		this->gameMode(event);
    	}
	    if(event.type == SDL_QUIT){
	    	this->serverManager.sendAction(Action(this->chellId,ACTION::QUIT,0));
            this->running = false;
	    }
    }    	
}	    

void InputManager::pauseMode(const SDL_Event& event){
 	Keypad keypad;
 	switch(event.type) {
		case SDL_KEYDOWN: {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
        	switch (keyEvent.keysym.sym) {
				case SDLK_ESCAPE:
    				this->gameView.pause();
        			break;
        		default:
        			break;
        	}
        }
    }
}

void InputManager::gameMode(const SDL_Event& event){
    Keypad keypad;
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
    SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
    switch(event.type) {
        case SDL_KEYDOWN: {                
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
                    case SDLK_b:
                    	this->serverManager.sendAction(Action(this->chellId,ACTION::JIG,0));
                    	break;
                    case SDLK_ESCAPE:
                        this->gameView.pause();
                        break;

                    //ESTO ESTA DE PRUEBA
                   case SDLK_n:
                        this->gameView.fullscreen();
                        break;
                    case SDLK_m:
                        this->gameView.windowed();
                        break;

            } // Fin KEY_DOWN
            break;
        }
        case SDL_KEYUP:{
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
            break;
        } // Fin KEY_UP
        case SDL_MOUSEWHEEL:{
            if(event.wheel.y > 0){// scroll up
                this->gameView.zoomIn();                        
            }
            else if(event.wheel.y < 0){// scroll down            
                this->gameView.zoomOut();
            }
            break;
        }// fin MOUSEWHEEL
        case SDL_MOUSEBUTTONDOWN:{
            int x, y;
            SDL_GetMouseState( &x, &y );
            switch(mouseEvent.button){
                case SDL_BUTTON_LEFT:                                                             
                    this->serverManager.sendAction(Action(this->chellId,ACTION::FIRE1,0));
                    break;
                case SDL_BUTTON_RIGHT:
                    this->serverManager.sendAction(Action(this->chellId,ACTION::FIRE2,0));
                    break;
                case SDL_BUTTON_MIDDLE:
                    this->gameView.pixelToCoord(x,y);
                    this->serverManager.sendAction(Action(this->chellId,ACTION::PING,0));
                    break;
            }
            break;
        }// fin MOUSEBUTTONDOWN
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
