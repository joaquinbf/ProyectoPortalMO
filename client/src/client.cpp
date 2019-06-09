#include "../include/client.h"

Client::Client()
: serverManager("localhost", PORT),
gameView(800,600,this->soundManager),
inputManager(this->serverManager,this->gameView,this->videoRecorder),
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
    uint32_t a = serverManager.receiveQuad();
    for(;a>0;a--){
        GameInfo gi = serverManager.receiveGameInfo();
        std::cout<<"id: "<<gi.getId()<<"\n";
        std::cout<<"map: "<<gi.getMapName()<<"\n";
        std::cout<<"playes: "<<gi.getPlayers()<<"\n";
        std::cout<<"capacity: "<<gi.getCapacity()<<"\n";
    }
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
    
    //GAME LOOP
    while (this->inputManager.isRunning()){
		while(this->updates.try_pop(update)){
			this->gameView.updateHandler(update);
		}
        for(int i = 0; i <10; ++i){
            this->gameView.render();            
            usleep(5000);
        }
        if(this->videoRecorder.isRecording()){
            this->videoRecorder.checkResolution(this->gameView.getResX(),this->gameView.getResY());
            this->videoRecorder.recordFrame(this->gameView.getRenderer());
        }
        this->gameView.step();
    }
    if(this->videoRecorder.isRecording()){
        this->videoRecorder.stopRecording();    
    }    
    this->serverManager.stop();
    this->updateReceiver.stop();
    this->inputManager.join();
    this->updateReceiver.join();
}
