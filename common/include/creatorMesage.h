#ifndef _CREATOR_MESAGE_H_
#define _CREATOR_MESAGE_H_

#include <cstdint>

#include "../include/entity.h"

class CreatorMesage{
private:
	ENTITY id_class;
	uint32_t id_object;
	float posx;
	float posy;
public:
	explicit CreatorMesage(ENTITY id_class,	uint32_t id_object,
	float posx,	float posy);
	~CreatorMesage();
	ENTITY getIdClass() const;
	uint32_t getIdObject() const;
	float getPosX() const;
	float getPosY() const;	
};

#endif
