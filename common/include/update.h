#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <cstdint>

#define ZOOM_FACTOR 100

#include "../include/types.h"

class Update{
private:
	COMMAND command;
	ENTITY idClass;
	uint32_t idObject;
	STATUS status;
	int32_t posX;
	int32_t posY;
	uint32_t direction;
public:
	Update();

	explicit Update(
		COMMAND command,
		ENTITY entity,
		uint32_t body_id,
		STATUS status,
		int32_t posx,
		int32_t posy,
		uint32_t dir);

	~Update();

	COMMAND getCommand() const;
	ENTITY getIdClass() const;
	uint32_t getIdObject() const;
	STATUS getStatus() const;
	int32_t getPosX() const;
	int32_t getPosY() const;
	uint32_t getDirection() const;

	void setCommand(COMMAND command);
	void setEntity(ENTITY entity);
	void setBodyId(uint32_t body_id);
	void setStatus(STATUS status);
	void setPosX(int32_t posX);
	void setPosY(int32_t posY);
	void setDirection(uint32_t direction);
};

#endif
