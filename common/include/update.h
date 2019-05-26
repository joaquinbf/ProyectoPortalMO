#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <cstdint>

#include "../include/status.h"

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
	DESTROY_COMMAND
};

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
	explicit Update(COMMAND command,ENTITY entity, uint32_t id, STATUS status, int32_t posx,
	int32_t posy, uint32_t dir);
	~Update();
	COMMAND getCommand() const;
	ENTITY getIdClass() const;
	uint32_t getIdObject() const;
	STATUS getStatus() const;
	int32_t getPosX() const;
	int32_t getPosY() const;
	uint32_t getDirection() const;
	void setIdObject(uint32_t idObject);
	void setStatus(STATUS status);
	void setPosX(int32_t posX);
	void setPosY(int32_t posY);
	void setDirection(uint32_t direction);
};

#endif
