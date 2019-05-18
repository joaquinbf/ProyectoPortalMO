#include "../include/protocolo.h"
#include "../include/socket.h"
#include <cstdint>
#include <string>
#include <arpa/inet.h>
#include <string.h>
#include <vector>

Protocolo::Protocolo(Socket *socket): socket(socket) {
}

void Protocolo::sendLen(uint32_t len) {
    this->sendUINT32(len);
}

uint32_t Protocolo::recvLen() {
    return this->recvUINT32();
}

void Protocolo::sendQuantity(uint32_t quantity) {
    this->sendUINT32(quantity);
}

uint32_t Protocolo::recvQuantity() {
    return this->recvUINT32();
}

void Protocolo::sendString(const std::string &string) {
    this->sendLen(string.size());
    this->socket->sendAll(string.data(), string.size());
}

std::string Protocolo::recvString() {
    uint32_t len = this->recvLen();
    std::vector<char> text(len + 1);

    this->socket->recvAll(text.data(), len);
    text.data()[len] = '\0';

    std::string string(text.data());
    return string;
}

void Protocolo::sendCommand(uint8_t command) {
    this->sendUINT8(command);
}

uint8_t Protocolo::recvCommand() {
    return this->recvUINT8();
}

void Protocolo::sendAction(uint8_t action) {
    this->sendUINT8(action);
}

uint8_t Protocolo::recvAction() {
    return this->recvUINT8();
}

void Protocolo::sendUINT8(uint8_t integer) {
    this->socket->sendAll((char *)&integer, sizeof(uint8_t));
}

uint8_t Protocolo::recvUINT8() {
    uint8_t integer;
    this->socket->recvAll((char *)&integer, sizeof(integer));
    return integer;
}

void Protocolo::sendUINT16(uint16_t integer) {
    uint16_t bigend = htons(integer);
    this->socket->sendAll((char *)&bigend, sizeof(uint16_t));
}

uint16_t Protocolo::recvUINT16() {
    uint16_t bigendian;
    uint16_t littleendian;
    this->socket->recvAll((char *)&bigendian, sizeof(uint16_t));
    littleendian = ntohs(bigendian);
    return littleendian;
}

void Protocolo::sendUINT32(uint32_t integer) {
    uint32_t bigend = htonl(integer);
    this->socket->sendAll((char *)&bigend, sizeof(bigend));
}

uint32_t Protocolo::recvUINT32() {
    uint32_t bigend;
    uint32_t littleendian;
    this->socket->recvAll((char *)&bigend, sizeof(bigend));
    littleendian = ntohl(bigend);
    return littleendian;
}
