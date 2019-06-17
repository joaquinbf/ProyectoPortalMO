#include "../include/pauseView.h"
#include <iostream>
PauseView::PauseView(const TextureManager& tm,const SdlWindow& window):
textureManager(tm),window(window),blackArea(0,0,600,600){
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
	if( TTF_Init() == -1 ) { 
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
	}
	this->font = TTF_OpenFont( "../resources/fonts/Roboto-Black.ttf", 28 );
	if(this->font == NULL){
		std::cout<<"NULL\n";
	}
	this->textColor = { 255, 255, 255 };
}

PauseView::~PauseView(){
	TTF_CloseFont( this->font );
}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));	
	std::string str = "PAUSA";
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->mTexture = SDL_CreateTextureFromSurface( this->window.getRenderer(), this->textSurface );
	Area src(0,0,textSurface->w,textSurface->h);
	Area dest(10,10,200,100);
	SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_RenderCopy(this->window.getRenderer(), mTexture, &sdlSrc, &sdlDest);    
}

void PauseView::mouseButtonDown(uint32_t x,uint32_t y){
	std::cout<<x<<" "<<y<<"\n";
}