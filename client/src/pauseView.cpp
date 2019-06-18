#include "../include/pauseView.h"
#include "../include/gameView.h"
#include <iostream>
PauseView::PauseView(const TextureManager& tm,const SdlWindow& window,GameView& gv,
	SoundManager& sm):
textureManager(tm),gameView(gv),soundManager(sm),blackArea(0,0,600,600),
pwPause(window,"Pausa",0.05,0.05),
pwResume(window,"Resumir",0.5,0.4),
pwOptions(window,"Opciones",0.5,0.5),
pwExit(window,"Salir",0.5,0.6),
pwScreenOpt(window,"Pantalla",0.5,0.4),
pwControlOpt(window,"Controles",0.5,0.5),
pwSoundOpt(window,"Sonido",0.5,0.6),
pwBack1(window,"Volver",0.5,0.7),
pwMusicVolume1(window,"Volumen de musica",0.3,0.3),
pwMusicVolume2(window,"<",0.6,0.4),
pwMusicVolume3(window,"100",0.7,0.4),
pwMusicVolume4(window,">",0.8,0.4),
pwFxVolume1(window,"Volumen de Efectos",0.3,0.6),
pwFxVolume2(window,"<",0.6,0.7),
pwFxVolume3(window,"100",0.7,0.7),
pwFxVolume4(window,">",0.8,0.7),
pwBack2(window,"Volver",0.5,0.9)	
{
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	double music,fx;
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
			pwScreenOpt.render(this->resx,this->resy);
			pwSoundOpt.render(this->resx,this->resy);
			pwControlOpt.render(this->resx,this->resy);
			pwBack1.render(this->resx,this->resy);
			break;
		case SCREENOPT:

			break;
		case SOUNDOPT:
			music = this->soundManager.getMusicVolume();
			pwMusicVolume3.changeString(std::to_string((int)music));

			fx = this->soundManager.getFxVolume();			
			pwFxVolume3.changeString(std::to_string((int)fx));

			pwMusicVolume1.render(this->resx,this->resy);
			pwMusicVolume2.render(this->resx,this->resy);
			pwMusicVolume3.render(this->resx,this->resy);
			pwMusicVolume4.render(this->resx,this->resy);
			pwFxVolume1.render(this->resx,this->resy);
			pwFxVolume2.render(this->resx,this->resy);
			pwFxVolume3.render(this->resx,this->resy);
			pwFxVolume4.render(this->resx,this->resy);
			pwBack2.render(this->resx,this->resy);
			break;
		case CONTROLOPT:
		
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
			if(this->pwSoundOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SOUNDOPT;
			}else if(this->pwScreenOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SCREENOPT;
			}else if( this->pwControlOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = CONTROLOPT;
			}else if( this->pwBack1.cursorOn(x,y,this->resx,this->resy)){
				this->status = INIT;
			}
			break;
		case SCREENOPT:

			break;
		case SOUNDOPT:
			if( this->pwBack2.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if (this->pwMusicVolume2.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicDown();
			} else if (this->pwMusicVolume4.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicUp();
			} else if (this->pwFxVolume2.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnFxDown();
			} else if (this->pwFxVolume4.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnFxUp();
			}


			break;
		case CONTROLOPT:

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
		case SCREENOPT:
			this->status = OPTIONS;
			break;
		case SOUNDOPT:
			this->status = OPTIONS;
			break;
		case CONTROLOPT:
			this->status = OPTIONS;
			break;
	}
}

bool PauseView::stoped(){
	return this->stop;
}