#include "../include/block.h"

#include <iostream>

Block::Block(const TextureManager& tm,const ENTITY e, int32_t x, int32_t y, 
	uint32_t width, uint32_t height) 
: Entity(x,y,width,height,0),frameArea(0, 0, 192, 192),entity(e){
	this->texturePtr = (SdlTexture*) tm.getBlockTexturePointer(this->entity);
}

Block::~Block(){}

void Block::setDirection(uint32_t dir){
	if(this->entity == ENTITY::STONE_BLOCK ||
	this->entity == ENTITY::METAL_BLOCK){
		return;
	}
	this->direction = dir;
}


/*
void Block::render(int resx,int resy,int width,int height){
	if(this->entity == ENTITY::STONE_BLOCK ||
	this->entity == ENTITY::METAL_BLOCK){
		this->texturePtr->render(this->frameArea, Area(resx,resy,width,height));
		return;
	}

	switch(this->direction){
		case 0:
			this->texturePtr->render(this->frameArea, Area(resx,resy,width,height));
			break;
		case 1:
			this->texturePtr->
				renderInAngle(this->frameArea, Area(resx,resy,width,height),90);	
			break;
		case 2:
			this->texturePtr->
				renderInAngle(this->frameArea, Area(resx,resy,width,height),180);
			break;
		case 3:
			this->texturePtr->
				renderInAngle(this->frameArea, Area(resx,resy,width,height),270);
			break;		
		default:
			this->texturePtr->render(this->frameArea, Area(resx,resy,width,height));
			break;
	}
	
}
*/

void Block::render(int cx,int cy,int resx,int resy,float scale){
	int a = this->posx*scale - (this->width/2)*scale + resx/2 ;
	int b = -this->posy*scale - (this->height/2)*scale + (2*resy)/3;
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

void Block::update(const Update& update){
	//ESTA ENTIDAD NO SE DEBERIA ACTUALIZAR
}
