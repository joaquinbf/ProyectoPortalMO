#ifndef _CREATOR_MESAGE_H_
#define _CREATOR_MESAGE_H_

#include <cstdint>

#include "../include/entity.h"

class CreatorMessage{
private:
	ENTITY id_class;
	uint32_t id_object;
	int32_t posx;
	int32_t posy;
	uint32_t dir;
public:
	explicit CreatorMessage(ENTITY id_class, uint32_t id_object,
	int32_t posx, int32_t posy, uint32_t dir);
	~CreatorMessage();
	ENTITY getIdClass() const;
	uint32_t getIdObject() const;
	int32_t getPosX() const;
	int32_t getPosY() const;
	uint32_t getDir() const;
};

#endif
