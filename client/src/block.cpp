#include "../include/block.h"

Block::Block(TextureManager& tm,const ENTITY e) 
: frameArea(0, 0, 192, 192),direction(0){
	this->texturePtr = tm.getBlockTexturePointer(e);
}

Block::~Block(){}

void Block::setDirection(uint32_t dir){
	this->direction = dir;
}

void Block::render(int resx,int resy,int width,int height){
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
				//renderFlipedDiagonal(this->frameArea, Area(resx,resy,width,height));	
			break;
		case 3:
			this->texturePtr->
				renderInAngle(this->frameArea, Area(resx,resy,width,height),270);
				//renderFlipedVertical(this->frameArea, Area(resx,resy,width,height));	
			break;		
		default:
			this->texturePtr->render(this->frameArea, Area(resx,resy,width,height));
			break;
	}
	
}

void Block::update(const Update& update){}
