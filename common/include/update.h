#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <cstdint>

#include "status.h"

class Update{
private:
	uint32_t idObject;
	STATUS status;
	float posX;
	float posY;
	uint32_t direction;
public:
	Update();
	explicit Update(uint32_t id, STATUS status, float posx,
	float posy, uint32_t dir);
	~Update();
	uint32_t getId() const;
	STATUS getStatus() const;
	float getPosX() const;
	float getPosY() const;
	uint32_t getDirection() const;
};

#endif
