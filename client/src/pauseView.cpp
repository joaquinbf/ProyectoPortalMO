#include "../include/pauseView.h"
#include "../include/gameView.h"

PauseView::PauseView(const TextureManager& tm,const SdlWindow& window,GameView& gv,
	SoundManager& sm):
textureManager(tm),gameView(gv),soundManager(sm),blackArea(0,0,600,600),
twPause(window,"Pausa",0.05,0.05),
twResume(window,"Resumir",0.5,0.4),
twOptions(window,"Opciones",0.5,0.5),
twExit(window,"Salir",0.5,0.6),
twScreenOpt(window,"Video",0.5,0.4),
twControlOpt(window,"Controles",0.5,0.5),
twSoundOpt(window,"Sonido",0.5,0.6),
twBack1(window,"Volver",0.5,0.7),
twMusicVolume1(window,"Volumen de musica",0.3,0.3),
twMusicVolume2(window,"<",0.6,0.4),
twMusicVolume3(window,"100",0.7,0.4),
twMusicVolume4(window,">",0.8,0.4),
twFxVolume1(window,"Volumen de Efectos",0.3,0.6),
twFxVolume2(window,"<",0.6,0.7),
twFxVolume3(window,"100",0.7,0.7),
twFxVolume4(window,">",0.8,0.7),
twBack2(window,"Volver",0.5,0.9),
twFull1(window,"Pantalla completa",0.3,0.3),
twFull2(window,"<",0.5,0.4),
twFull3(window,"no",0.6,0.4),
twFull4(window,">",0.7,0.4),
twRes1(window,"Resolucion",0.3,0.6),
twRes2(window,"<",0.45,0.7),
twRes3(window,"800x600",0.6,0.7),
twRes4(window,">",0.7,0.7),
twBack3(window,"Volver",0.5,0.9)
{
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){
	atexit(TTF_Quit);
}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	int music,fx;
	this->resx = resx;
	this->resy = resy;
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));	
	twPause.render(resx,resy);
	switch(this->status){
		case INIT:
			twResume.render(this->resx,this->resy);
			twOptions.render(this->resx,this->resy);
			twExit.render(this->resx,this->resy);
			break;	
		case OPTIONS:
			twScreenOpt.render(this->resx,this->resy);
			twSoundOpt.render(this->resx,this->resy);
			twControlOpt.render(this->resx,this->resy);
			twBack1.render(this->resx,this->resy);
			break;
		case SCREENOPT:
			if(this->gameView.isFullscreen()){
				twFull3.changeString("si");
				twRes2.lock();
				twRes4.lock();
			}else{
				twFull3.changeString("no");
				twRes2.unlock();
				twRes4.unlock();
			}
			twRes3.changeString(std::to_string(resx)
				+"x"+std::to_string(resy));
			twFull1.render(this->resx,this->resy);
			twFull2.render(this->resx,this->resy);
			twFull3.render(this->resx,this->resy);
			twFull4.render(this->resx,this->resy);
			twRes1.render(this->resx,this->resy);
			twRes2.render(this->resx,this->resy);
			twRes3.render(this->resx,this->resy);
			twRes4.render(this->resx,this->resy);
			twBack3.render(this->resx,this->resy);
			break;
		case SOUNDOPT:
			music = this->soundManager.getMusicVolume();
			twMusicVolume3.changeString(std::to_string(music));

			fx = this->soundManager.getFxVolume();			
			twFxVolume3.changeString(std::to_string(fx));

			twMusicVolume1.render(this->resx,this->resy);
			twMusicVolume2.render(this->resx,this->resy);
			twMusicVolume3.render(this->resx,this->resy);
			twMusicVolume4.render(this->resx,this->resy);
			twFxVolume1.render(this->resx,this->resy);
			twFxVolume2.render(this->resx,this->resy);
			twFxVolume3.render(this->resx,this->resy);
			twFxVolume4.render(this->resx,this->resy);
			twBack2.render(this->resx,this->resy);
			break;
		case CONTROLOPT:
		
			break;
	}
	
}

void PauseView::mouseButtonDown(uint32_t x,uint32_t y){
	switch(this->status){
		case INIT:
			if(this->twResume.cursorOn(x,y,this->resx,this->resy)){
				this->gameView.pause();
			}else if(this->twOptions.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			}else if( this->twExit.cursorOn(x,y,this->resx,this->resy)){
				this->stop = true;
			}
			break;	
		case OPTIONS:
			if(this->twSoundOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SOUNDOPT;
			}else if(this->twScreenOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SCREENOPT;
			}else if( this->twControlOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = CONTROLOPT;
			}else if( this->twBack1.cursorOn(x,y,this->resx,this->resy)){
				this->status = INIT;
			}
			break;
		case SCREENOPT:
			if( this->twBack3.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if( this->twFull2.cursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->twFull4.cursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->twRes2.cursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.nextRes();
				} 
			} else if( this->twRes4.cursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.nextRes();
				} 
			}

			break;
		case SOUNDOPT:
			if( this->twBack2.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if (this->twMusicVolume2.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicDown();
			} else if (this->twMusicVolume4.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicUp();
			} else if (this->twFxVolume2.cursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnFxDown();
			} else if (this->twFxVolume4.cursorOn(x,y,this->resx,this->resy)){
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