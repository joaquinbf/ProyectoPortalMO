#include "../include/laser.h"

Laser::Laser(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height,uint32_t direction):
Entity(x,y,width,height,direction),
frameArea(0,109,228,10)
{
	this->texturePtr = tm.getLaserTexturePointer();
}

Laser::~Laser(){}

void Laser::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	Area renderArea(a,b,this->width*scale,this->height*scale);
	switch(this->direction){
		case 0:
			this->texturePtr->render(this->frameArea, renderArea);
			break;
		case 1:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,90);	
			break;
		case 2:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,180);
			break;
		case 3:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,270);
			break;		
		default:
			this->texturePtr->render(this->frameArea, renderArea);
			break;
	}
}

void Laser::update(const Update& update){
	//esta texture no se actualiza
}