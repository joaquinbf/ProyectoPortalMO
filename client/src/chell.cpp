#include "../include/chell.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Chell::Chell(const SdlWindow& window)
: idleTexture(IDLE_TEXTURE,window), jigTexture(JIG_TEXTURE,window),
 frameArea(0, 0, 168, 243){
	this->texturePtr = &this->idleTexture;
	this->actionPtr = &Chell::jigAction;
	this->framex = 0;	
	this->framey = 0;	
}

Chell::~Chell(){}

void Chell::idleAction(){
	this->texturePtr = &this->idleTexture;
	frameArea = Area(0, 0, 168, 243);
}

void Chell::jigAction(){
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

int Chell::render(int x, int y){
	(*this.*actionPtr)();
	return (*this->texturePtr).render(this->frameArea, Area(x,y,104,215));
}
