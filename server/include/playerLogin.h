#ifndef _PLAYER_LOGIN_H_
#define _PLAYER_LOGIN_H_

#include <list>
#include <string>

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

#include "../include/game.h"
#include "../include/player.h"
#include "../include/disconnecter.h"

class PlayerLogin : public Thread{
private: 
	std::list<Game*>* games;
	Socket peer;
public:
	explicit PlayerLogin(std::list<Game*>* games,Socket peer);
	virtual void run() override;
	
};

#endif
