#include "../include/creator.h"

Creator::Creator(uint32_t id_class,	uint32_t id_object,
	float posx,	float posy) : id_class(id_class), id_object(id_object),
posx(posx),posy(posy){}

Creator::~Creator(){}

uint32_t Creator::getIdClass() const{
	return this->id_class;
}

uint32_t Creator::getIdObject() const{
	return this->id_object;
}

float Creator::getPosX() const{
	return this->posx;
}

float Creator::getPosY() const{
	return this->posy;
}
