#include "../include/pauseView.h"

PauseView::PauseView(const TextureManager& tm):
textureManager(tm),blackArea(0,0,600,600){
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));
}

//void Pause::mouse