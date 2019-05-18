#ifndef __PROTOCOLO_H__
#define __PROTOCOLO_H__

#include "socket.h"
#include <cstdint>
#include <string>
#include <iostream>

/* Clase encargada de controlar el formato de comunicacion entre el
 * server y el client */
class Protocolo {
private:
    Socket *socket;

public:
    /* Instancia un protocolo */
    explicit Protocolo(Socket *socket);

    /* Envia una longitud */
    void sendLen(uint32_t len);

    /* Recibe una longitud */
    uint32_t recvLen();

    /* Envia una cantidad */
    void sendQuantity(uint32_t quantity);

    /* Recibe una cantidad */
    uint32_t recvQuantity();

    /* Envia una cadena */
    void sendString(const std::string &string);

    /* Envia un string */
    std::string recvString();

    /* Envia un comando */
    void sendCommand(uint8_t command);

    /* Recibe un comando */
    uint8_t recvCommand();

    /* Envia una accion */
    void sendAction(uint8_t action);

    /* Recibe una accion */
    uint8_t recvAction();

private:
    /* Envia un entero de 8bits sin signo */
    void sendUINT8(uint8_t integer);

    /* Recibe un entero de 8bits sin signo */
    uint8_t recvUINT8();

    /* Envia un entero de 16bits sin signo */
    void sendUINT16(uint16_t integer);

    /* Recibe un entero de 16 bits sin signo */
    uint16_t recvUINT16();

    /* Envia un entero de 32bits sin signo */
    void sendUINT32(uint32_t integer);

    /* Recibe un entero de 32bits sin signo */
    uint32_t recvUINT32();
};

#endif
