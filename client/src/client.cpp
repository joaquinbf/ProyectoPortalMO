#include "../include/client.h"
#include <iostream>
Client::Client()
: serverManager("localhost", PORT),
gameView(800,600,this->soundManager),
inputManager(this->serverManager,this->gameView,this->videoRecorder),
updateReceiver(this->serverManager,this->updates)
{}

Client::~Client(){}

void Client::main(){
	if(!this->login()){
        this->game();
    }   	
}

static bool ends_with(std::string const & value, std::string const & ending){
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int Client::login(){
    std::list<GameInfo> games;
    std::list<std::string> maps;
    uint32_t a = this->serverManager.receiveQuad();
    for(;a>0;a--){
        GameInfo gi = this->serverManager.receiveGameInfo();
        games.push_back(gi);
    }

    DIR           *dirp;
    struct dirent *directory;
    dirp = opendir(MAP_SAVE_ROUTE);
    if (dirp){
        while ((directory = readdir(dirp)) != NULL){
            if(ends_with(std::string(directory->d_name),
                std::string(".yaml"))){
                maps.push_back(std::string(directory->d_name));
            }            
        }
        closedir(dirp);
    }   
    int b = 0;
    QApplication app(b,NULL);
    Login login(this->serverManager,games,maps);
    login.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    login.show();
    return login.exec();
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
