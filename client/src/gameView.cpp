#include "../include/gameView.h"

GameView::GameView(uint32_t x, uint32_t y) : 
resx(x),resy(y),window(x,y), textureManager(window),myChell(nullptr),
myChellId(0), scale(1)
{}

GameView::~GameView(){
	if(this->myChell != nullptr){
		delete this->myChell;
	}
	for( auto it = this->entities.begin(); it != this->entities.end(); ++it ){
		if(it->second != nullptr){
			delete it->second;
		}
	}
}

void GameView::render(){
	this->window.fill(); // Repinto el fondo gris
	for( auto it = this->entities.begin(); it != this->entities.end(); ++it ){
		it->second->render(this->myChell->getPosX(),this->myChell->getPosY(),
			this->resx,this->resy,this->scale);
	}
	this->window.setBrightness(0.5);
	if(this->myChell != nullptr){
		this->myChell->renderCentered(this->resx,this->resy,this->scale);	
	}
	//this->textureManager.getBlackTexture()->setAlpha(255*(1-this->scale));     
	//this->textureManager.getBlackTexture()->render(Area(0,0,600,600),Area(0,0,this->resx,this->resy));
    this->window.render();
}


void GameView::updateHandler(Update update){
	EntityFactory ef;
	uint32_t id;
	switch(update.getCommand()){
		case COMMAND::CREATE_COMMAND:			
			id = update.getIdObject();
			if(id == this->myChellId){ 
				this->myChell = (Chell *)ef.create(update,this->textureManager);
			} else {
				this->entities[id] = ef.create(update,this->textureManager);
			}
			break;
		case COMMAND::UPDATE_COMMAND:
			id = update.getIdObject();
			if(id == this->myChellId){
				this->myChell->update(update);
			}else{
				this->entities[id]->update(update);
			}
			break;
		case COMMAND::DESTROY_COMMAND:
			//FALTA IMPLEMENTAR
			break;
		default:
			break;
	}
}

void GameView::zoomIn(){
	if(this->scale < 1){
		this->scale+=0.05;
	}
}

void GameView::zoomOut(){
	if(this->scale > 0.5){
		this->scale-=0.05;
	}
}

uint32_t GameView::getChellId() const{
	return this->myChellId;
}

void GameView::setChellId(uint32_t id){
	this->myChellId = id;
}

void GameView::show(){
	this->window.show();	
}

void GameView::fullscreen(){
	this->window.fullscreen();
	this->resx=this->window.getResX();
	this->resy=this->window.getResY();
}

void GameView::windowed(){
	this->window.windowed();
	this->resx=this->window.getResX();
	this->resy=this->window.getResY();
}