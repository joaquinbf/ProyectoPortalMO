#ifndef _PLAYER_LOGIN_H_
#define _PLAYER_LOGIN_H_

#include <vector>
#include <string>


#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

#include "../include/game.h"
#include "../include/player.h"

class PlayerLogin : public Thread{
private: 
	std::vector<Game*>& games;
	Socket peer;
public:
	explicit PlayerLogin(std::vector<Game*>& games,Socket peer);
	
	virtual void run() override;
	
};

#endif
