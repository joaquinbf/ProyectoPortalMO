#include "../include/creatorMesage.h"

CreatorMesage::CreatorMesage(uint32_t id_class,	uint32_t id_object,
	float posx,	float posy) : id_class(id_class), id_object(id_object),
posx(posx),posy(posy){}

CreatorMesage::~CreatorMesage(){}

uint32_t CreatorMesage::getIdClass() const{
	return this->id_class;
}

uint32_t CreatorMesage::getIdObject() const{
	return this->id_object;
}

float CreatorMesage::getPosX() const{
	return this->posx;
}

float CreatorMesage::getPosY() const{
	return this->posy;
}
