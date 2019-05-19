#include <iostream>

#include "../include/chell.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Chell::Chell(const SdlWindow& window)
: idleTexture(IDLE_TEXTURE,window), jigTexture(JIG_TEXTURE,window), 
runTexture(RUNNING_TEXTURE,window), stopTexture(STOPING_TEXTURE,window),
turnTexture(TURN_TEXTURE,window), frameArea(0, 0, 165, 215){
	this->texturePtr = &this->idleTexture;
	this->actionPtr = &Chell::idleAction;
	this->framex = 0;	
	this->framey = 0;	
	this->direction = 1;
	this->turning = false;
	this->running = false;
}

Chell::~Chell(){}

int Chell::render(const Area& renderArea){
	int s;
	if( this-> direction == 1){
		s = (*this->texturePtr).render(this->frameArea, renderArea);
	} else if(this-> direction == 0){
		s = (*this->texturePtr).renderFliped(this->frameArea, renderArea);
	}
	(*this.*actionPtr)();
	return s;
}

void Chell::idleAction(){
	this->actionPtr = &Chell::idleAction;
	this->texturePtr = &this->idleTexture;
	frameArea = Area(0, 0, 165, 215);
}
void Chell::jig(){
	this->framex = 0;
	this->framey = 0;
	this->jigAction();
}

void Chell::jigAction(){
	this->actionPtr = &Chell::jigAction;
	this->texturePtr = &this->jigTexture;
	this->frameArea = Area(169*this->framex, 244*this->framey, 168, 243);
	this->framex+=1;
	if(this->framey == 8){
		if(this->framex == 7){
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 9){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::run(int dir){
	if(this->turning){
		this->turnAction();	
		return;
	}
	if(dir != this->direction){
		this->turn(dir);
		return;
	}
	if(!this->running){
		this->framex = 0;
		this->framey = 0;
	}
	this->runAction();
}

void Chell::stop(int dir){
	this->running = false;
	if(this->turning){
		this->turnAction();	
		return;
	}
	this->framex = 0;
	this->framey = 0;
	this->stopAction();
}

void Chell::runAction(){
	this->actionPtr = &Chell::runAction;
	this->texturePtr = &this->runTexture;
	this->running = true;
	this->frameArea = Area(195*this->framex, 205*this->framey+1, 194, 204);
	this->framex+=1;
	if(this->framey == 1){
		if(this->framex == 2){
			this->framex = 0;
			this->framey = 0;	
		}
	}
	if(this->framex == 8){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::stopAction(){
	this->actionPtr = &Chell::stopAction;
	this->texturePtr = &this->stopTexture;
	this->frameArea = Area(166*this->framex, 216*this->framey+1, 165, 215);
	this->framex+=1;
	if(this->framey == 1){
		if(this->framex == 2){
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 10){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::turn(int dir){
	this->turning = true;
	this->framex = 0;
	this->turnAction();	
}

void Chell::turnAction(){
	this->actionPtr = &Chell::turnAction;
	this->texturePtr = &this->turnTexture;	
	this->frameArea = Area(191*this->framex+5, 1, 190, 200);
	this->framex+=1;
	if(this->framex == 8){
		this->turning = false;
		if(this->direction == 1){
			this->direction = 0;
		}else{
			this->direction = 1;
		}
		this->stop(this->direction);
	}
}
