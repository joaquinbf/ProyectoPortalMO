#include "../include/update.h"

Update::Update(uint32_t id, STATUS status, float posx,
	float posy, float speedx, float speedy) 
: idObject(id),status(status), posX(posx), posY(posy), speedX(speedx),
speedY(speedy) {}

Update::~Update(){}

uint32_t Update::getId() const{
	return this->idObject;
}

STATUS Update::getStatus() const{
	return this->status;
}

float Update::getPosX() const{
	return this->posX;
}

float Update::getPosY() const{
	return this->posY;
}

float Update::getSpeedX() const{
	return this->speedX;
}

float Update::getSpeedY() const{
	return this->speedY;
}
