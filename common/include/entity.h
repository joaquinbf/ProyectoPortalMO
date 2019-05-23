#ifndef _ENTITY_H_
#define _ENTITY_H_

enum ENTITY: uint8_t {
	CHELL,
	ROCK
};

class Entity{
public:
	Entity(){}
	virtual ~Entity(){}
	virtual void render(int resx,int resy,int width,int height){}
};


#endif
