#include "../include/chell.h"

Chell::Chell(const SdlWindow& window,uint32_t posx,uint32_t posy,
		uint32_t width,uint32_t height,uint32_t dir)
: Entity(posx,posy,width,height,dir),
idleTexture(CHELL_IDLE_TEXTURE,window), 
jigTexture(CHELL_JIG_TEXTURE,window), 
runTexture(CHELL_RUNNING_TEXTURE,window), 
stopTexture(CHELL_STOPING_TEXTURE,window),
turnTexture(CHELL_TURN_TEXTURE,window), 
jumpRiseTexture(CHELL_JUMP_RISE_TEXTURE,window),
jumpApexTexture(CHELL_JUMP_APEX_TEXTURE,window), 
jumpFallTexture(CHELL_JUMP_FALL_TEXTURE,window),
jumpLandTexture(CHELL_JUMP_LAND_TEXTURE,window), 
fireTexture(CHELL_FIRE_TEXTURE,window),
fireToIdleTexture(CHELL_FIRE_TO_IDLE_TEXTURE,window),
frameArea(0, 0, 104, 215),
status(CHELL_IDLE){
	this->texturePtr = &this->idleTexture;
	this->actionPtr = &Chell::idleAction;
	this->framex = 0;	
	this->framey = 0;
}

Chell::~Chell(){}

void Chell::renderCentered(int resx,int resy, float scale){
	int a=(resx/2)-((this->width*scale)/2);
    int b=(7*resy/8)-(this->height*scale);
    Area renderArea(a,b,this->width*scale,this->height*scale);
	if( this-> direction == 1){
		this->texturePtr->render(this->frameArea, renderArea);
	} else if(this-> direction == 0){
		this->texturePtr->renderFlipedHorizontal(this->frameArea, renderArea);
	}
	(this->*actionPtr)();
}

void Chell::render(int resx,int resy,int width,int height){

	return;
}

void Chell::update(const Update& update){
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
	if(this->status == CHELL_RUNNING || 
		this->status == CHELL_FALLING ||
		this->status == CHELL_JIGING ){
		return;
	}
	if(this->status != CHELL_IDLE){
		this->framex = 0;
		this->framey = 0;
		this->idleAction();	
	}
}


void Chell::idleAction(){
	this->status = CHELL_IDLE;
	this->actionPtr = &Chell::idleAction;
	this->texturePtr = &this->idleTexture;	
	frameArea = Area(105*this->framex, 0, 104, 215);
	this->framex+=1;
	if(this->framex == 7){
		this->framex = 0;
	}
}
void Chell::jig(){	
	if(this->status == CHELL_IDLE){
		this->framex = 0;
		this->framey = 0;
		this->jigAction();	
	}	
}

void Chell::jigAction(){
	this->status = CHELL_JIGING;
	this->actionPtr = &Chell::jigAction;
	this->texturePtr = &this->jigTexture;
	this->frameArea = Area(169*this->framex, 244*this->framey, 168, 243);
	this->framex+=1;
	if(this->framey == 8){
		if(this->framex == 7){
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 9){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::run(int dir){
	if(this->status == CHELL_RUNNING ||
		this->status == CHELL_TURNING ||
		this->status == CHELL_LANDING){
		this->direction = dir;
		this->framex = 0;
		this->framey = 0;
		this->runAction();	
	}	
}

void Chell::runAction(){
	this->status = CHELL_RUNNING;
	this->actionPtr = &Chell::runAction;
	this->texturePtr = &this->runTexture;
	this->frameArea = Area(195*this->framex, 205*this->framey+1, 194, 204);
	this->framex+=1;
	if(this->framey == 1){
		if(this->framex == 2){
			this->framex = 0;
			this->framey = 0;	
		}
	}
	if(this->framex == 8){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::stop(int dir){
	if(this->status == CHELL_RUNNING){
		this->framex = 0;
		this->framey = 0;
		this->stopAction();	
	}	
}

void Chell::stopAction(){
	this->status = CHELL_STOPING;
	this->actionPtr = &Chell::stopAction;
	this->texturePtr = &this->stopTexture;
	this->frameArea = Area(166*this->framex, 216*this->framey+1, 165, 215);
	this->framex+=1;
	if(this->framey == 1){
		if(this->framex == 2){
			this->actionPtr = &Chell::idleAction;
		}
	}
	if(this->framex == 10){
		this->framex = 0;
		this->framey+=1;
	}
}

void Chell::turn(int dir){
	if(this->status == CHELL_RUNNING ||
		this->status == CHELL_IDLE ||
		this->status == CHELL_LANDING){
		this->framex = 0;
		this->turnAction();	
	}
}

void Chell::turnAction(){
	this->status = CHELL_TURNING;
	this->actionPtr = &Chell::turnAction;
	this->texturePtr = &this->turnTexture;	
	this->frameArea = Area(193*this->framex+6, 1, 185, 200);
	this->framex+=1;
	if(this->framex == 8){
		if(this->direction == 1){
			this->direction = 0;
		}else{
			this->direction = 1;
		}
		this->stop(this->direction);
	}
}

void Chell::jump(){
	if(this->status == CHELL_IDLE ||
		this->status == CHELL_RUNNING){
		this->framex = 0;
		this->jumpAction();
	}
}

void Chell::jumpAction(){
	this->status = CHELL_JUMPING;
	this->actionPtr = &Chell::jumpAction;
	this->texturePtr = &this->jumpRiseTexture;
	this->frameArea = Area(144*this->framex+1, 0, 143, 227);
	this->framex+=1;
	if(this->framex == 5){
		this->texturePtr = &this->jumpApexTexture;
		this->frameArea = Area(0, 0, 137, 207);
		this->actionPtr = &Chell::idleAction;
	}	
	
}

void Chell::fall(int dir){
	this->direction=dir;
	if(this->status != CHELL_FALLING){
		this->framex = 0;
		this->fallAction();
	}
}

void Chell::fallAction(){
	this->status = CHELL_FALLING;
	this->actionPtr = &Chell::fallAction;
	this->texturePtr = &this->jumpFallTexture;
	this->frameArea = Area(157*this->framex, 0, 156, 217);
	this->framex+=1;
	if(this->framex == 4){		
		this->framex = 0;
	}
}

void Chell::land(){
	if(this->status == CHELL_FALLING){
		this->framex = 0;
		this->landAction();
	}
}

void Chell::landAction(){
	this->status = CHELL_LANDING;
	this->actionPtr = &Chell::landAction;
	this->texturePtr = &this->jumpLandTexture;
	this->frameArea = Area(231*this->framex+80, 2, 150, 196);
	this->framex+=1;
	if(this->framex == 2){		
		this->actionPtr = &Chell::idleAction;
	}
}

void Chell::fire(int dir){
	if(this->status == CHELL_IDLE ){
		this->framex = 0;
		this->fireAction();	
	}else if(this->status == CHELL_RUNNING){
		this->framex = 0;
		//this->fireRunningAction();	
		this->fireAction();	
	}else if(this->status == CHELL_JUMPING || 
			this->status == CHELL_FALLING){
		this->framex = 0;
		//this->fireRunningAction();	
		this->fireAction();	
	}		
}

void Chell::fireAction(){
	this->status = CHELL_FIRE;
	this->actionPtr = &Chell::fireAction;
	this->texturePtr = &this->fireTexture;
	this->frameArea = Area(171*this->framex, 0, 170, 212);
	this->framex+=1;
	if(this->framex >= 5){
		this->texturePtr = &this->fireToIdleTexture;		
		this->frameArea = Area(144*(this->framex-5), 0, 143, 212);
	}
	if(this->framex == 8){
		this->actionPtr = &Chell::idleAction;
	}
}
