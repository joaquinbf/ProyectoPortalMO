#include "../include/chell.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Chell::Chell(const SdlWindow& window)
: idleTexture(IDLE_TEXTURE,window), jigTexture(JIG_TEXTURE,window),
 frameArea(0, 0, 104, 215){
	this->texturePtr = &this->idleTexture;
	this->actionPtr = &Chell::idleAction;
	this->framex = 0;	
	this->framey = 0;	
}

Chell::~Chell(){}

void Chell::idleAction(){
	this->actionPtr = &Chell::idleAction;
	this->texturePtr = &this->idleTexture;
	frameArea = Area(0, 0, 104, 215);
}

void Chell::jigAction(){
	this->actionPtr = &Chell::jigAction;
	this->texturePtr = &this->jigTexture;
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
	this->frameArea = Area(169*this->framex, 244*this->framey, 168, 243);
}

int Chell::render(const Area& renderArea){
	int s = (*this->texturePtr).render(this->frameArea, renderArea);
	(*this.*actionPtr)();
	return s;
}
