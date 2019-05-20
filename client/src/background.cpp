#include <iostream>
#include "../include/background.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Background::Background(const SdlWindow& window) : 
backgroundTexture(BACKGROUND_TEXTURE,window){
	this->widthRendered=400;
	this->heightRendered=200;
}

Background::~Background(){}

int Background::render(int x, int y, int resx, int resy){	
	if(100+x < 0){
		while(400+100+x<0){
			x+=400;
		}
		float a = (float) (100+x)/(-400);
		float b = (float) (400+100+x)/400;
		a*=resx;
		b*=resx;
		this->backgroundTexture.render(Area(400+100+x,290+y,-100-x,200),
		 Area(0,0,(int)a,resy));
		this->backgroundTexture.render(Area(0,290+y,400+100+x,200), 
			Area((int)a,0,(int)b,resy));
		return 0;
	}else if(100+x>600-400 ){
		while(100+x>resx){
			x-=600;
		}
		float a = (float) (400+100-x)/400;
		float b = 1-a;
		a*=resx;
		b*=resx;
		this->backgroundTexture.render(Area(600-(400-x+100),290+y,400-x+100,200),
		 Area(0,0,(int)a,resy));
		this->backgroundTexture.render(Area(0,290+y,x-100,200), 
			Area((int)a,0,(int)b,resy));
		return 0;
	}else{
		Area frameArea(100+x,290+y,400,200);
		Area renderArea(0,0,resx,resy);
		return this->backgroundTexture.render(frameArea, renderArea);	
	}
}
