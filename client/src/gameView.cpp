#include "../include/gameView.h"

GameView::GameView(uint32_t x, uint32_t y, const SoundManager& sm) : 
resx(x),resy(y),window(x,y), textureManager(window), soundManager(sm),myChell(nullptr),
myChellId(0), scale(1), paused(false), background(window),
pauseView(this->textureManager){
	this->cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
	SDL_SetCursor(this->cursor);
}

GameView::~GameView(){
	if(this->myChell != nullptr){
		delete this->myChell;
	}
	for( auto it : this->entities){
		if(it.second != nullptr){
			delete it.second;
		}
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			delete it.second;
		}
	}
	SDL_FreeCursor(this->cursor);
}

void GameView::step(){
	for( auto it : this->entities){
		if(it.second != nullptr){
			it.second->step();
		}
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			it.second->step();
		}
	}
	if(this->myChell != nullptr){
		this->myChell->step();
	}
	this->danceMode = false;
}

void GameView::render(){
	this->updateResolution();
	this->window.fill(); // Repinto el fondo gris
	int32_t posx = 0;
	int32_t posy = 0;
	if(this->myChell != nullptr){
		posx = this->myChell->getPosX();
		posy = this->myChell->getPosY();
	}
	if(this->danceMode){
		this->background.setColorMod(rand()%255,rand()%255,rand()%255);	
	}
	this->background.render(posx,posy,this->resx,this->resy,this->scale);

	for( auto it : this->entities){
		if(it.second != nullptr){			
			if(this->danceMode){
				it.second->setColorMod(rand()%255,rand()%255,rand()%255);
			}
			it.second->render(posx,posy,this->resx,this->resy,this->scale);	
		}		
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			it.second->render(posx,posy,this->resx,this->resy,this->scale);	
		}		
	}
	if(this->myChell != nullptr){
		this->myChell->renderCentered(this->resx,this->resy,this->scale);	
	}
	if(this->paused){
		this->pauseView.render(this->resx,this->resy);	
	}
    this->window.render();
}

void GameView::updateHandler(Update update){
	EntityFactory ef;
	uint32_t id;
	switch(update.getCommand()){
	case COMMAND::CREATE_COMMAND:			
		id = update.getIdObject();
		if(id == this->myChellId){ 
			this->myChell = (Chell *)ef.create(update,this->textureManager,this->soundManager);
		} else if(update.getIdClass() == ENTITY::CHELL){
			this->chells[id] = (Chell *) ef.create(update,this->textureManager,this->soundManager);
			this->chells[id]->setColorMod(this->getRand(),this->getRand(),this->getRand());
		} else {
			this->entities[id] = ef.create(update,this->textureManager,this->soundManager);
		}
		break;
	case COMMAND::UPDATE_COMMAND:
		id = update.getIdObject();
		if(id == this->myChellId){
			this->myChell->update(update);
		} else if (this->chells.find(id) != this->chells.end()){
			this->chells[id]->update(update);
		} else if( this->entities.find(id) != this->entities.end()){
			this->entities[id]->update(update);
		}
		break;
	case COMMAND::DESTROY_COMMAND:
		id = update.getIdObject();
		if(id == this->myChellId){
			delete this->myChell;
			this->myChell = nullptr;				
		} else if (this->chells.find(id) != this->chells.end()){
			this->chells.erase(id);
		} else if( this->entities.find(id) != this->entities.end()){
			this->entities.erase(id);
		}
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
	if(this->scale > 0.25){
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

void GameView::updateResolution(){
	this->resx=this->window.getResX();
	this->resy=this->window.getResY();
}

void GameView::fullscreen(){
	this->window.fullscreen();
}

void GameView::windowed(){
	this->window.windowed();
}

bool GameView::isPaused() const{
	return this->paused;
}

void GameView::pause(){
	this->paused = !this->paused;
}

int32_t GameView::pixelToCoordX(int32_t x) const{
	int32_t cordx = this->myChell->getPosX();
	int32_t a=x-(this->resx/2);
    a = a/this->scale + cordx;
    return a;
}

int32_t GameView::pixelToCoordY(int32_t y) const{
	int32_t cordy = this->myChell->getPosY();
    int32_t b=y-(2*this->resy/3);
    b = -b/this->scale + cordy;
    return b;
}

SDL_Renderer* GameView::getRenderer() const{
	return this->window.getRenderer();
}

uint32_t GameView::getResX() const{
	return this->resx;
}

uint32_t GameView::getResY() const{
	return this->resy;
}

uint8_t GameView::getRand() const{
	double n = ((double)rand()/RAND_MAX);
	if(n < 0.333){
		return 180;
	}else if(n < 0.666){
		return 220;
	}else{
		return 255;
	}
}

PauseView* GameView::getPausePtr(){
	return &this->pauseView;
}