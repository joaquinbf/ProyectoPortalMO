#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <cstdint>

#include "status.h"

class Update{
private:
	uint32_t idObject;
	STATUS status;
	int32_t posX;
	int32_t posY;
	uint32_t direction;
public:
	Update();
	explicit Update(uint32_t id, STATUS status, int32_t posx,
	int32_t posy, uint32_t dir);
	~Update();
	uint32_t getId() const;
	STATUS getStatus() const;
	int32_t getPosX() const;
	int32_t getPosY() const;
	uint32_t getDirection() const;
};

#endif
