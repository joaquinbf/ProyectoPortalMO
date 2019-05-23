#include "../include/update.h"

Update::Update() : idObject(0),status(NONE), posX(0), posY(0), direction(0){}

Update::Update(uint32_t id, STATUS status, float posx,
	float posy, uint32_t dir) 
: idObject(id),status(status), posX(posx), posY(posy), direction(dir) {}

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

uint32_t Update::getDirection() const{
	return this->direction;
}
