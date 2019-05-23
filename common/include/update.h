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
	float speedX;
	float speedY;
public:
	Update();
	explicit Update(uint32_t id, STATUS status, float posx,
	float posy, float speedx, float speedy);
	~Update();
	uint32_t getId() const;
	STATUS getStatus() const;
	float getPosX() const;
	float getPosY() const;
	float getSpeedX() const;
	float getSpeedY() const;
};

#endif
