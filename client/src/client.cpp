#include "../include/client.h"

Client::Client()
: serverManager("localhost", PORT),
updateReceiver(this->serverManager,this->updates)
{}

Client::~Client(){}

void Client::main(){
	if(!this->login()){
        this->game();
    }   	
}

int Client::login(){
    std::list<GameInfo> games;
    std::list<std::string> maps;
    uint32_t a = this->serverManager.receiveQuad();
    for(;a>0;a--){
        GameInfo gi = this->serverManager.receiveGameInfo();
        games.push_back(gi);
    }
    a = this->serverManager.receiveQuad();
    for(;a>0;a--){
        std::string map = this->serverManager.receiveLine();
        maps.push_back(map);
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
    GameView gameView(800,600,this->soundManager);
    InputManager inputManager(this->serverManager,gameView,this->videoRecorder,
        gameView.getPausePtr());
    gameView.setChellId(chellId);

    this->running = true;
    Update update;

    inputManager.start();
    this->updateReceiver.start();
    this->soundManager.playMusic();
    
    //GAME LOOP
    while (inputManager.isRunning()){
		while(this->updates.try_pop(update)){
			gameView.updateHandler(update);
		}        
        gameView.render();            
        usleep(50000);        
        if(this->videoRecorder.isRecording()){
            this->videoRecorder.checkResolution(gameView.getResX(),gameView.getResY());
            this->videoRecorder.recordFrame(gameView.getRenderer());
        }
        gameView.step();
    }
    if(this->videoRecorder.isRecording()){
        this->videoRecorder.stopRecording();    
    }    
    this->serverManager.sendAction(Action(gameView.getChellId(),ACTION::QUIT,0,0));
    this->serverManager.stop();
    this->updateReceiver.stop();
    inputManager.join();
    this->updateReceiver.join();
}
