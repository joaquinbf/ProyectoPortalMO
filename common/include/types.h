#ifndef _TYPES_H_
#define _TYPES_H_

#include <cstdint>

enum ENTITY: uint8_t {
	NONE_ENTITY,
	CHELL,
	STONE_BLOCK,
	METAL_BLOCK,
	METAL_TRIAG_BLOCK,
	LAUNCH_BLOCK
};

enum COMMAND : uint8_t{
	NONE_COMMAND,
	CREATE_COMMAND,
	UPDATE_COMMAND,
	DESTROY_COMMAND,
	STOP_THREAD_COMMAND
};

enum STATUS: uint8_t {
	NONE_STATUS,
	CHELL_IDLE,
	CHELL_RUNNING,
	CHELL_TURNING,
	CHELL_STOPING,
	CHELL_JUMPING,
	CHELL_JUMPING_APEX,
	CHELL_FALLING,
	CHELL_LANDING,
	CHELL_FIRE,
	CHELL_FIRE_TO_IDLE,
	CHELL_JIGING

};

#endif
