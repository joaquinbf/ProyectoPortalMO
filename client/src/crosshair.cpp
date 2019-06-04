#include "../include/crosshair.h"

Crosshair::Crosshair(const TextureManager& tm):
frameArea(0,0,480,480){
	this->texturePtr = (SdlTexture *) tm.getCrosshairTexturePointer();
}

Crosshair::~Crosshair(){}

void Crosshair::render(){
	int x, y;
    SDL_GetMouseState( &x, &y );
    this->texturePtr->render(this->frameArea,Area(x-20,y-20,40,40));
}
