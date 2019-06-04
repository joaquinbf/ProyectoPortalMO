#include "../include/client.h"

Client::Client(int x, int y)
: serverManager("localhost", PORT), 
gameView(x,y),
inputManager(this->serverManager,this->gameView),
updateReceiver(this->serverManager,this->updates)
{
	
}

Client::~Client(){}

void Client::main(){
	this->login();
	this->game();
}

void Client::login(){
	//aca haria algo
}

void Client::game(){
    uint32_t chellId = serverManager.receiveChellId();
    this->gameView.setChellId(chellId);
    
    this->running = true;
    Update update;
    
    this->inputManager.start();
    this->updateReceiver.start();
    this->gameView.show();
    //GAME LOOP
    while (this->inputManager.isRunning()){
		while(this->updates.try_pop(update)){
			this->gameView.updateHandler(update);
		}
        for(int i = 0; i <10; ++i){
            this->gameView.render();
            usleep(10000);
        }
        this->gameView.step();
    }
    this->serverManager.stop();
    this->updateReceiver.stop();
    this->inputManager.join();
    this->updateReceiver.join();    
}
