#include "../include/pauseView.h"
#include "../include/gameView.h"
#include <iostream>
PauseView::PauseView(const TextureManager& tm,const SdlWindow& window,GameView& gv):
textureManager(tm),gameView(gv),blackArea(0,0,600,600),pwPause(window,"Pausa",0.05,0.05),
pwResume(window,"Resumir",0.5,0.333),pwOptions(window,"Opciones",0.5,0.5),
pwExit(window,"Salir",0.5,0.666){
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	this->resx = resx;
	this->resy = resy;
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));	
	pwPause.render(resx,resy);
	switch(this->status){
		case INIT:
			pwResume.render(this->resx,this->resy);
			pwOptions.render(this->resx,this->resy);
			pwExit.render(this->resx,this->resy);	
			break;	
		case OPTIONS:

			break;
	}
	
}

void PauseView::mouseButtonDown(uint32_t x,uint32_t y){
	switch(this->status){
		case INIT:
			if(this->pwResume.cursorOn(x,y,this->resx,this->resy)){
				this->gameView.pause();
			}else if(this->pwOptions.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			}else if( this->pwExit.cursorOn(x,y,this->resx,this->resy)){
				this->stop = true;
			}
			break;	
		case OPTIONS:

			break;
	}
}

void PauseView::back(){
	switch(this->status){
		case INIT:
			this->gameView.pause();				
			break;	
		case OPTIONS:
			this->status = INIT;
			break;
	}
}

bool PauseView::stoped(){
	return this->stop;
}