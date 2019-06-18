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
pwBack2(window,"Volver",0.5,0.9),
pwFull1(window,"Pantalla completa",0.3,0.3),
pwFull2(window,"<",0.5,0.4),
pwFull3(window,"no",0.6,0.4),
pwFull4(window,">",0.7,0.4),
pwRes1(window,"Resolucion",0.3,0.6),
pwRes2(window,"<",0.45,0.7),
pwRes3(window,"800x600",0.6,0.7),
pwRes4(window,">",0.7,0.7),
pwBack3(window,"Volver",0.5,0.9)
{
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	int music,fx;
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
			if(this->gameView.isFullscreen()){
				pwFull3.changeString("si");
				pwRes2.lock();
				pwRes4.lock();
			}else{
				pwFull3.changeString("no");
				pwRes2.unlock();
				pwRes4.unlock();
			}
			pwRes3.changeString(std::to_string(resx)
				+"x"+std::to_string(resy));
			pwFull1.render(this->resx,this->resy);
			pwFull2.render(this->resx,this->resy);
			pwFull3.render(this->resx,this->resy);
			pwFull4.render(this->resx,this->resy);
			pwRes1.render(this->resx,this->resy);
			pwRes2.render(this->resx,this->resy);
			pwRes3.render(this->resx,this->resy);
			pwRes4.render(this->resx,this->resy);
			pwBack3.render(this->resx,this->resy);
			break;
		case SOUNDOPT:
			music = this->soundManager.getMusicVolume();
			pwMusicVolume3.changeString(std::to_string(music));

			fx = this->soundManager.getFxVolume();			
			pwFxVolume3.changeString(std::to_string(fx));

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
			if( this->pwBack3.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if( this->pwFull2.cursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->pwFull4.cursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->pwRes2.cursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.nextRes();
				} 
			} else if( this->pwRes4.cursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.nextRes();
				} 
			}

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