#include "../include/pauseView.h"
#include <iostream>
PauseView::PauseView(const TextureManager& tm,const SdlWindow& window):
textureManager(tm),blackArea(0,0,600,600),pwPause(window,"Pausa",0.05,0.05),
pwResume(window,"Resumir",0.5,0.333),pwOptions(window,"Opciones",0.5,0.5),
pwExit(window,"Salir",0.5,0.666){
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));	
	pwPause.render(resx,resy);
	pwResume.render(resx,resy);
	pwOptions.render(resx,resy);
	pwExit.render(resx,resy);
}

void PauseView::mouseButtonDown(uint32_t x,uint32_t y){
	std::cout<<x<<" "<<y<<"\n";
}