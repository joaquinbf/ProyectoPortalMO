#include "../include/action.h"

Action::Action() {
}

Action::Action(ACTION ac,uint32_t param): action(ac), param(param){}

Action::~Action(){}

ACTION Action::getAction() const{
	return this->action;
}

uint32_t Action::getParam() const{
	return this->param;
}
