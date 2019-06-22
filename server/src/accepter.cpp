#include "../include/accepter.h"

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

Accepter::~Accepter(){
    for(auto it :  this->games){
        delete it.second;
    }
    for(PlayerLogin* pl: this->logins){
        if(pl->isJoinable()){
            pl->join();
        }
        delete pl;
    }
}

void Accepter::run() {    
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            if(this->keep_running){
                PlayerLogin* playerLogin = new PlayerLogin(&this->games,std::move(peer));
                playerLogin->start();
                this->logins.push_back(playerLogin);    
                for(PlayerLogin* pl: this->logins){
                    if(pl->isJoinable()){
                        pl->join();
                    }
                }
                for(auto it : this->games){
                    if(it.second->isFinished()){
                        it.second->stop();
                        this->games.erase(it.first);
                        delete it.second;                        
                    }
                }
            }            
        }
    } catch (const ConnectionErrorException &e) {
    }
    for(auto it :  this->games){
        it.second->stop();
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
