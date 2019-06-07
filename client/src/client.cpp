#include "../include/client.h"

Client::Client()
: serverManager("localhost", PORT),
gameView(800,600,this->soundManager),
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
    this->soundManager.playMusic();
    VideoRecorder vr(800,600);
    //GAME LOOP
    while (this->inputManager.isRunning()){
		while(this->updates.try_pop(update)){
			this->gameView.updateHandler(update);
		}
        for(int i = 0; i <10; ++i){
            this->gameView.render();            
            usleep(5000);
        }
        vr.recordFrame(this->gameView.getRenderer());
        this->gameView.step();
    }
    vr.close();
    this->serverManager.stop();
    this->updateReceiver.stop();
    this->inputManager.join();
    this->updateReceiver.join();
}
