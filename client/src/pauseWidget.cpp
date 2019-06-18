#include "../include/pauseWidget.h"
#include <iostream>
PauseWidget::PauseWidget(const SdlWindow& window,const std::string str,float x,float y):
window(window),str(str),x(x),y(y),selected(false){
	if( TTF_Init() == -1 ) { 
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
	}
	this->font = TTF_OpenFont(FONT_DIR, 42 );
	if(this->font == NULL){
		std::cout<<"NULL\n";
	}
	this->textColor = { 255, 255, 255 };
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

PauseWidget::~PauseWidget(){
	TTF_CloseFont(this->font );
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
}

void PauseWidget::render(uint32_t resx,uint32_t resy){
	Area src(0,0,this->textSurface->w,this->textSurface->h);
	Area dest((resx-this->textSurface->w)*this->x,
		(resy-this->textSurface->h)*this->y,
		this->textSurface->w,
		this->textSurface->h);
	SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_RenderCopy(this->window.getRenderer(), this->texturePtr, &sdlSrc, &sdlDest);    
}

void PauseWidget::changeColor(uint8_t r,uint8_t g,uint8_t b){
	this->textColor = {r,g,b};
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

bool PauseWidget::cursorOn(uint32_t px,uint32_t py,uint32_t resx,uint32_t resy){
	if(px < (resx-this->textSurface->w)*this->x){
		return false;
	} else if (px > (resx-this->textSurface->w)*this->x+this->textSurface->w){
		return false;
	} else if (py < (resy-this->textSurface->h)*this->y){
		return false;
	}  else if (py > (resy-this->textSurface->h)*this->y+this->textSurface->h){
		return false;
	} else{
		return true;
	}
} 

void PauseWidget::select(){
	this->changeColor(255,200,0);
}
