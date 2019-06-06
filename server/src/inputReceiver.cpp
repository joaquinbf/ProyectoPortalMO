#include "../include/inputReceiver.h"
#include <iostream>

InputReceiver::InputReceiver(Protocol& p) : running(true), protocol(p){

}

InputReceiver::~InputReceiver(){}

void InputReceiver::run(){
	try{
		while(this->running){
			Action action= this->protocol.receiveAction();
			std::cout << "input recv : " << action.getAction() << std::endl;
			 //bloqueante
			if(action.getAction() == ACTION::QUIT){
				std::cout<<"cerro\n";
				this->protocol.close();
				this->running = false;
			} else {
				this->inputPtr->push(std::move(action));
			}
		}
	}catch(const ConnectionErrorException &e){

	}
}

void InputReceiver::stop(){
	this->running = false;
}

void InputReceiver::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputPtr = ptr;
}
