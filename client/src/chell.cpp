#include "../include/chell.h"

Chell::Chell(const TextureManager& tm,int32_t posx,int32_t posy,
		uint32_t width,uint32_t height,uint32_t dir)
: Entity(posx,posy,width,height,dir),
textureManager(tm),
frameArea(0, 0, 104, 215),
status(CHELL_IDLE){
	this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
	this->actionPtr = &Chell::idleAction;
	this->frame = 0;	
	this->framey = 0;
}

Chell::~Chell(){}

void Chell::step(){
	(this->*actionPtr)();
}

void Chell::renderCentered(int resx,int resy, float scale){
	int a=(resx/2)-((this->width*scale)/2);
    int b=(2*resy/3)-(this->height*scale)/2;
    Area renderArea(a,b,this->width*scale,this->height*scale);
	if( this-> direction == 1){
		this->texturePtr->render(this->frameArea, renderArea);
	} else if(this-> direction == 0){
		this->texturePtr->renderFlipedHorizontal(this->frameArea, renderArea);
	}
}

void Chell::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;	
	if( this-> direction == 1){
		this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
	} else if(this-> direction == 0){
		this->texturePtr->renderFlipedHorizontal(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
	}
}

int32_t Chell::getPosX(){
	return this->posx;
}

int32_t Chell::getPosY(){
	return this->posy;
}

void Chell::update(const Update& update){
	this->posx = update.getPosX();
	this->posy = update.getPosY();
	switch(update.getStatus()){
		case CHELL_RUNNING:
			this->run(update.getDirection());
			break;
		case CHELL_STOPING:
			this->stop(update.getDirection());
			break;
		case CHELL_FALLING:
			this->fall(update.getDirection());						
			break;
		case CHELL_LANDING:
			break;
		case CHELL_FIRE:
			this->fire(update.getDirection());
			break;
		case CHELL_IDLE:
			this->idle();
			break;
		case CHELL_TURNING:
			this->turn(update.getDirection());
			break;
		case CHELL_JUMPING:
			this->jump();
			break;
		case CHELL_JIGING:
			this->jig();
			break;
		default:	
			this->idle();
			break;
	}
}

void Chell::idle(){
	if(this->status != CHELL_IDLE){
		this->frame = 0;
		this->framey = 0;
		this->idleAction();	
	}
}


void Chell::idleAction(){
	this->status = CHELL_IDLE;
	this->actionPtr = &Chell::idleAction;
	this->texturePtr = (SdlTexture *) 
		this->textureManager.getChellTexturePointer(this->status);
	frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 7){
		this->frame = 0;
	}
}

void Chell::jig(){	
	if(this->status != CHELL_JIGING){
		this->frame = 0;
		this->jigAction();	
	}	
}

void Chell::jigAction(){
	this->status = CHELL_JIGING;
	this->actionPtr = &Chell::jigAction;
	this->texturePtr = (SdlTexture *) 
		this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 79){	
		this->actionPtr = &Chell::idleAction;
		this->frame = 0;
	}
	
}

void Chell::run(int dir){
	if(this->status != CHELL_RUNNING){
		this->direction = dir;
		this->frame = 0;
		this->runAction();	
	}
}

void Chell::runAction(){
	this->status = CHELL_RUNNING;
	this->actionPtr = &Chell::runAction;
	this->texturePtr = (SdlTexture *) 
		this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 12){
		this->frame = 0;
	}
}

void Chell::stop(int dir){
	if(this->status != CHELL_STOPING){
		this->frame = 0;
		this->stopAction();	
	}	
}

void Chell::stopAction(){
	this->status = CHELL_STOPING;
	this->actionPtr = &Chell::stopAction;
	this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 12){
		this->frame = 0;
		this->actionPtr = &Chell::idleAction;
	}
}

void Chell::turn(int dir){
	if(this->status != CHELL_TURNING){
		this->frame = 0;
		this->turnAction();	
	}
}

void Chell::turnAction(){
	this->status = CHELL_TURNING;
	this->actionPtr = &Chell::turnAction;
	this->texturePtr = (SdlTexture *) 
		this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 8){
		if(this->direction == 1){
			this->direction = 0;
		}else{
			this->direction = 1;
		}
		this->frame = 0;
		this->actionPtr = &Chell::idleAction;
	}	
}

void Chell::jump(){
	if(this->status != CHELL_JUMPING){
		this->frame = 0;
		this->jumpAction();
	}
}

void Chell::jumpAction(){
	this->status = CHELL_JUMPING;
	this->actionPtr = &Chell::jumpAction;
	this->texturePtr = (SdlTexture *) 
		this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 5 ){
		this->status = CHELL_JUMPING_APEX;
		this->texturePtr = (SdlTexture *) 
			this->textureManager.getChellTexturePointer(this->status);
		this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
		this->actionPtr = &Chell::idleAction;
		this->frame = 0;
	}		
}

void Chell::fall(int dir){
	this->direction=dir;
	if(this->status != CHELL_FALLING){
		this->frame = 0;
		this->fallAction();
	}
}

void Chell::fallAction(){
	this->status = CHELL_FALLING;
	this->actionPtr = &Chell::fallAction;
	this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
	this->frameArea =  this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 4){		
		this->frame = 0;
	}
}

void Chell::land(){
	if(this->status != CHELL_LANDING){
		this->frame = 0;
		this->landAction();
	}
}

void Chell::landAction(){
	this->status = CHELL_LANDING;
	this->actionPtr = &Chell::landAction;
	this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame == 2){		
		this->actionPtr = &Chell::idleAction;
	}
}

void Chell::fire(int dir){
	if(this->status != CHELL_FIRE){
		this->frame = 0;
		this->fireAction();	
	}else if(this->status == CHELL_RUNNING){
		this->frame = 0;
		//this->fireRunningAction();	
		this->fireAction();	
	}else if(this->status == CHELL_JUMPING || 
			this->status == CHELL_FALLING){
		this->frame = 0;
		//this->fireRunningAction();	
		this->fireAction();	
	}		
}

void Chell::fireAction(){
	this->status = CHELL_FIRE;
	this->actionPtr = &Chell::fireAction;
	this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
	this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame);
	this->frame+=1;
	if(this->frame >= 5){
		this->status = CHELL_FIRE_TO_IDLE;
		this->texturePtr = (SdlTexture *) this->textureManager.getChellTexturePointer(this->status);
		this->frameArea = this->textureManager.getChellFrameArea(this->status,this->frame-5);
	}
	if(this->frame == 8){
		this->actionPtr = &Chell::idleAction;
	}
}
