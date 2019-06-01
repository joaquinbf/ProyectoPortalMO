#include "../include/action.h"

Action::Action() {
}

Action::Action(uint32_t id,ACTION ac,uint32_t param): id(id),action(ac), param(param){}

Action::~Action(){}

uint32_t Action::getId()const{
	return this->id;
}

ACTION Action::getAction() const{
	return this->action;
}

uint32_t Action::getParam() const{
	return this->param;
}
