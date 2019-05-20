#include "../include/background.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Background::Background(const SdlWindow& window) : 
backgroundTexture(BACKGROUND_TEXTURE,window){}

Background::~Background(){}

int Background::render(const Area& renderArea){	
	Area frameArea(0,0,600,400);
	return this->backgroundTexture.render(frameArea, renderArea);	
}
