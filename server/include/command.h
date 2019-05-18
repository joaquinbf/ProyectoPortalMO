#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <cstdint>

/* Comandos de moviento de Chell enviados por el cliente */
enum COMMAND: uint8_t {
    KEY_UP    = 0x00;
    KEY_RIGHT = 0x01;
    KEY_DOWN  = 0x02;
    KEY_LEFT  = 0x03;
    JUMP      = 0x04;
    FIRE      = 0x05
};

#endif
