#include "../include/creatorMessage.h"

CreatorMessage::CreatorMessage(ENTITY id_class,	uint32_t id_object,
	float posx,	float posy) : id_class(id_class), id_object(id_object),
posx(posx),posy(posy){}

CreatorMessage::~CreatorMessage(){}

ENTITY CreatorMessage::getIdClass() const{
	return this->id_class;
}

uint32_t CreatorMessage::getIdObject() const{
	return this->id_object;
}

float CreatorMessage::getPosX() const{
	return this->posx;
}

float CreatorMessage::getPosY() const{
	return this->posy;
}