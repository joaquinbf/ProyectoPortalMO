#ifndef _STATUS_H_
#define _STATUS_H_

#include <cstdint>

enum STATUS: uint8_t {
	NONE,
	CHELL_RUNNING_LEFT,
	CHELL_RUNNING_RIGHT,
	CHELL_FALLING,
	CHELL_LANDING,
};

#endif
