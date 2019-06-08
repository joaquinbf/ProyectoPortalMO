#include "../include/pin.h"

Pin::Pin(uint32_t id,int32_t x,int32_t y):
id(id),x(x),y(y),cont(30){

}

Pin::~Pin(){}

uint32_t Pin::getId() const{
	return this->id;
}

bool Pin::hasUpdate(){
	if(this->cont == 30 || this->cont == 0){
		return true;
	} else {
		-- this->cont;
		return false;
	}
}

Update Pin::getUpdate(){
	if( this-> cont == 30){
		-- this->cont;
		return Update(COMMAND::CREATE_COMMAND,ENTITY::PIN,this->id,
			STATUS::NONE_STATUS,this->x,this->y,0);
	} //this-> cont == 0
	return Update(COMMAND::DESTROY_COMMAND,ENTITY::PIN,this->id,
		STATUS::NONE_STATUS,0,0,0);

}