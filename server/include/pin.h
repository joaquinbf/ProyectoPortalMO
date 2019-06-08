#ifndef _PIN_H_
#define _PIN_H_

#include "../.././common/include/update.h"

class Pin{
	uint32_t id;
	int32_t x;
	int32_t y;
	uint32_t cont;
public:
	explicit Pin(uint32_t id,int32_t x,int32_t y);
	~Pin();
	bool hasUpdate();
	Update getUpdate();
};

#endif
