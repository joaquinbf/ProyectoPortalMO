#include "../include/chell.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Chell::Chell(const SdlWindow& window)
: idleTexture(IDLE_TEXTURE,window), jigTexture(JIG_TEXTURE,window), 
runTexture(RUNNING_TEXTURE,window), stopTexture(STOPING_TEXTURE,window),
 frameArea(0, 0, 165, 215){
	this->texturePtr = &this->idleTexture;
	this->actionPtr = &Chell::idleAction;
	this->framex = 0;	
	this->framey = 0;	
}

Chell::~Chell(){}

int Chell::render(const Area& renderArea){
	int s = (*this->texturePtr).render(this->frameArea, renderArea);
	(*this.*actionPtr)();
	return s;
}

void Chell::idleAction(){
	this->actionPtr = &Chell::idleAction;
	this->texturePtr = &this->idleTexture;
	frameArea = Area(0, 0, 165, 215);
}

void Chell::jigAction(){
	this->actionPtr = &Chell::jigAction;
	this->texturePtr = &this->jigTexture;
	this->frameArea = Area(169*this->framex, 244*this->framey, 168, 243);
	this->framex+=1;
	if(this->framey == 8){
		if(this->framex == 7){
			this->framex = 0;
			this->framey = 0;	
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 9){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::runRightAction(){
	this->actionPtr = &Chell::runRightAction;
	this->texturePtr = &this->runTexture;
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

void Chell::stopRightAction(){
	this->actionPtr = &Chell::stopRightAction;
	this->texturePtr = &this->stopTexture;
	this->frameArea = Area(166*this->framex, 216*this->framey+1, 165, 215);
	this->framex+=1;
	if(this->framey == 1){
		if(this->framex == 2){
			this->framex = 0;
			this->framey = 0;	
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 10){
		this->framex = 0;
		this->framey+=1;
	}
}


