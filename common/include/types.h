#ifndef _TYPES_H_
#define _TYPES_H_

#include <cstdint>

enum ENTITY: uint8_t {
	NONE_ENTITY,
	CHELL,
	STONE_BLOCK,
	METAL_BLOCK,
	METAL_TRIAG_BLOCK,
	LAUNCH_BLOCK,
	RECEIVER_BLOCK,
	ROCK,
	BUTTON,
	GATE,
	ACID,
	BULLET,
	LASER,
	PIN,
	CAKE,
	PORTAL1,
	PORTAL2
};

enum COMMAND : uint8_t{
	NONE_COMMAND,
	CREATE_COMMAND,
	UPDATE_COMMAND,
	DESTROY_COMMAND
};

enum STATUS: uint8_t {
	NONE_STATUS 			= 0x00,
	CHELL_IDLE              = 0x01,
	CHELL_RUNNING           = 0x02,
	CHELL_TURNING           = 0x03,
	CHELL_STOPING           = 0x04,
	CHELL_JUMPING           = 0x05,
	CHELL_JUMPING_APEX      = 0x06,
	CHELL_FALLING           = 0x07,
	CHELL_LANDING           = 0x08,
	CHELL_FIRE              = 0x09,
	CHELL_FIRE_TO_IDLE		= 0x0A,
	CHELL_JIGING            = 0x0B,
	CHELL_DIE               = 0x0C,
	BUTTON_ON               = 0x0D,
	BUTTON_OFF              = 0x0E,
	GATE_OPENED             = 0x0F,
	GATE_CLOSED				= 0x10,
	GATE_OPENING			= 0x11,
	GATE_CLOSING            = 0x12
};

enum DIRECTION: uint8_t {
	RIGHT_DIRECTION = 0x00,
	DOWN_DIRECTION  = 0x01,
	LEFT_DIRECTION  = 0x02,
	UP_DIRECTION    = 0x03
};

#endif
