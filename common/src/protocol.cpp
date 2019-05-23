#include <string>

#include "../include/protocol.h"
#include "../include/socket.h"

Protocol::Protocol(){}

Protocol::Protocol(Socket&& socket) : socket(std::move(socket)){}

Protocol::~Protocol(){}

void Protocol::close(){
	this->socket.close();
}

Protocol::Protocol(Protocol&& other){
	this->socket=std::move(other.socket);
}


Protocol& Protocol::operator=(Protocol&& other){
	if(this != &other){
		this->socket=std::move(other.socket);
	}
	return *this;
}

void Protocol::sendByte(const uint8_t byte) const{
	uint8_t aux = byte;
	while(this->socket.send(&aux,1) <= 0){}
}

void Protocol::sendDoble(const uint16_t byte) const{
	uint16_t aux = htons(byte);
	this->sendByte((aux) & 0xFF);
	this->sendByte((aux >> 8) & 0xFF);
}

void Protocol::sendQuad(const uint32_t byte) const{
	uint32_t aux = htonl(byte);
	for(int i = 0; i<4; ++i){
		this->sendByte((aux >> 8*i) & 0xFF);
	}
}

void Protocol::sendLine(const std::string& line) const{
	int charsSent = 0;
	int s;
	int len = line.size();
	this->sendQuad((uint32_t)len);
	while(len > charsSent){
		s = this->socket.send(line.c_str()+charsSent, len-charsSent);
		if(s >= 0){
		 	charsSent += s;
		}else{
			throw ConnectionErrorException("Error en Protocol::shutdown: %s\n",
                                     strerror(errno));
		}
	}
}

uint8_t Protocol::receiveByte() const{
	uint8_t aux = 0;
	int s = this->socket.receive(&aux,1);
	while(s != 1){
		if(s < 0){
			throw ConnectionErrorException(
				"Error en socket receiveByte:%s\n",strerror(errno));
		}
		s = this->socket.receive(&aux,1);
	}
	return aux;
}

uint16_t Protocol::receiveDoble() const{
	uint16_t buf=0;
	uint16_t aux;
	for(int i = 0; i<2; ++i){
		aux=this->receiveByte();
		buf += aux<<(i*8);
	}
	return ntohs(buf);
}

uint32_t Protocol::receiveQuad() const{
	uint32_t buf = 0;
	uint32_t aux;
	for(int i = 0; i<4; ++i){
		aux=this->receiveByte();
		buf += aux<<(i*8);
	}
	return ntohl(buf);
}

std::string Protocol::receiveLine() const{
	uint32_t len = this->receiveQuad();
	uint32_t s;
	uint32_t charsReceived = 0;
	std::string line;
	char aux[200];
	while(len > charsReceived){
		memset(&aux,0,200);
		if(len-charsReceived > 200){
			s = this->socket.receive(&aux,199);
		}else{
			s = this->socket.receive(&aux,len - charsReceived);
		}
		if(s <= 0){
			throw ConnectionErrorException("Error en Protocol::shutdown: %s\n",
                                     strerror(errno));
		}
		charsReceived += s;
		line +=std::string(aux);
	}
	return line;
}

void Protocol::sendCreator(const CreatorMessage creator) const{
	this->sendByte(creator.getIdClass());
	this->sendQuad(creator.getIdObject());
	this->sendQuad(creator.getPosX());
	this->sendQuad(creator.getPosY());
}

CreatorMessage Protocol::receiveCreator() const{
	ENTITY idc = (ENTITY) this->receiveByte();
	uint32_t ido = this->receiveQuad();
	float posx = this->receiveQuad();
	float posy = this->receiveQuad();
	return CreatorMessage(idc,ido,posx,posy);
}

void Protocol::sendAction(const Action action) const{
	this->sendByte(action.getAction());
	this->sendQuad(action.getParam());
}

Action Protocol::receiveAction() const{
	ACTION ac =(ACTION) this->receiveByte();
	uint32_t param = this->receiveQuad();
	return Action(ac,param);
}


void Protocol::sendUpdate(const Update update) const{
	this->sendQuad(update.getId());
	this->sendByte(update.getStatus());
	this->sendQuad(update.getPosX());
	this->sendQuad(update.getPosY());
	this->sendQuad(update.getSpeedX());
	this->sendQuad(update.getSpeedY());
}

Update Protocol::receiveUpdate() const{
	uint32_t id = this->receiveQuad();
	STATUS st =(STATUS) this->receiveByte();
	float posx = this->receiveQuad();
	float posy = this->receiveQuad();
	float speedx = this->receiveQuad();
	float speedy = this->receiveQuad();
	return Update(id,st,posx,posy,speedx,speedy);
}
