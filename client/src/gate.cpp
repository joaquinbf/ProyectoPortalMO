#include "../include/gate.h"

Gate::Gate(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height):
Entity(x,y,width,height,0),
textureManager(tm), frameArea(0,0,192,384), frame(0), status(STATUS::GATE_CLOSED){
	this->actionPtr = &Gate::closed;
	this->texturePtr = (SdlTexture *) this->textureManager.getGateTexturePointer(this->status);
}

Gate::~Gate(){}

void Gate::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;	
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
	(this->*actionPtr)();
}

void Gate::update(const Update& update){
	switch(update.getStatus()){
		case STATUS::GATE_OPENED:
			this->opened();
			break;
		case STATUS::GATE_CLOSED:
			this->closed();
			break;
		case STATUS::GATE_OPENING:
			this->open();
			break;
		case STATUS::GATE_CLOSING:
			this->close();
			break;
		default:
			break;
	}
}

void Gate::opened(){
	this->status = STATUS::GATE_OPENED;
	this->actionPtr = &Gate::opened;
	this->texturePtr = (SdlTexture *) this->textureManager.getGateTexturePointer(this->status);
	this->frame = 18;
	this->frameArea = Area(0,1,192,384);
}

void Gate::closed(){
	this->status = STATUS::GATE_CLOSED;
	this->actionPtr = &Gate::closed;
	this->texturePtr = (SdlTexture *) this->textureManager.getGateTexturePointer(this->status);
	this->frame = 0;
	this->frameArea =  Area(0,0,192,384);
}
void Gate::open(){
	this->status = STATUS::GATE_OPENING;
	this->actionPtr = &Gate::open;
	this->texturePtr = (SdlTexture *) this->textureManager.getGateTexturePointer(this->status);	
	this->frameArea =  this->textureManager.getGateFrameArea(this->frame);
	++this->frame;
	if(this->frame == 19){
		this->actionPtr = &Gate::opened;
	}
}

void Gate::close(){
	this->status = STATUS::GATE_CLOSING;
	this->actionPtr = &Gate::open;
	this->texturePtr = (SdlTexture *) this->textureManager.getGateTexturePointer(this->status);
	
	this->frameArea =  this->textureManager.getGateFrameArea(this->frame);
	--this->frame;
	if(this->frame == 0){
		this->actionPtr = &Gate::closed;
	}
}
