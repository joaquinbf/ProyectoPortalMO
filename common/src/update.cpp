#include "../include/update.h"
#include "../include/status.h"
#include "../include/entity.h"

Update::Update() : command(COMMAND::NONE_COMMAND), idClass(ENTITY::NONE_ENTITY), idObject(0),
	status(STATUS::NONE_STATUS), posX(0), posY(0), direction(0){}

Update::Update(COMMAND command, ENTITY entity,uint32_t id, STATUS status, int32_t posx,
	int32_t posy, uint32_t dir)
: command(command), idClass(entity), idObject(id),status(status), posX(posx), posY(posy), 
	direction(dir) {}

Update::~Update(){}

COMMAND Update::getCommand() const{
	return this->command;
}

ENTITY Update::getIdClass() const{
	return this->idClass;
}

uint32_t Update::getIdObject() const{
	return this->idObject;
}

STATUS Update::getStatus() const{
	return this->status;
}

int32_t Update::getPosX() const{
	return this->posX;
}

int32_t Update::getPosY() const{
	return this->posY;
}

uint32_t Update::getDirection() const{
	return this->direction;
}

void Update::setIdObject(uint32_t idObject) {
	this->idObject = idObject;
}

void Update::setStatus(STATUS status) {
	this->status = status;
}

void Update::setPosX(int32_t posX) {
	this->posX = posX;
}

void Update::setPosY(int32_t posY) {
	this->posY = posY;
}

void Update::setDirection(uint32_t direction) {
	this->direction = direction;
}
