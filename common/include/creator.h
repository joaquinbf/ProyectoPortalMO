#ifndef _CREATOR_H_
#define _CREATOR_H_

class Creator{
private:
	uint32_t id_class;
	uint32_t id_object;
	float posx;
	float posy;
public:
	explicit Creator(uint32_t id_class,	uint32_t id_object,
	float posx,	float posy);
	~Creator();
	uint32_t getIdClass() const;
	uint32_t getIdObject() const;
	float getPosX() const;
	float getPosY() const;	
};

#endif
