#include <iostream>
#include "../include/background.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Background::Background(const SdlWindow& window) : 
backgroundTexture(BACKGROUND_TEXTURE,window){
	this->resx = 1800;
	this->resy = 1100;
	this->widthRendered=400;
	this->heightRendered=300;
}

Background::~Background(){}

void Background::render(int x, int y, int rx, int ry,float scale){	
	Area renderArea(0,0,rx,ry);
	int32_t a = (this->resx/2) + x/10 - this->widthRendered/(2*scale);
	int32_t b= (this->resy/2) + y/10 - this->widthRendered/(2*scale);
	if(a < 0){
		a = 0;
	}
	if(a >  this->resx - this->widthRendered/scale ){
		a = this->resx - this->widthRendered/scale;
	}
    if(b < 0){
		b = 0;
	}
	if(b >  this->resy - this->heightRendered/scale ){
		b = this->resy - this->heightRendered/scale;
	}	
    
    Area frameArea(a,b,	this->widthRendered/scale,this->heightRendered/scale);
	this->backgroundTexture.render(frameArea,renderArea);
}
