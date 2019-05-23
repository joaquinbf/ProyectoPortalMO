#ifndef _CREATOR_MESAGE_H_
#define _CREATOR_MESAGE_H_

#include <cstdint>

class CreatorMesage{
private:
	uint32_t id_class;
	uint32_t id_object;
	float posx;
	float posy;
public:
	explicit CreatorMesage(uint32_t id_class,	uint32_t id_object,
	float posx,	float posy);
	~CreatorMesage();
	uint32_t getIdClass() const;
	uint32_t getIdObject() const;
	float getPosX() const;
	float getPosY() const;	
};

#endif
