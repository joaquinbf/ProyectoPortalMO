#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <cstdint>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <list>

#include "../include/serverManager.h"
#include "../include/inputManager.h"
#include "../include/updateReceiver.h"
#include "../include/gameView.h"

#include "../../common/include/port.h"
#include "../../common/include/update.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/types.h"

class Client{
private:
	bool running;
	ServerManager serverManager;
	ProtectedQueue<Update> updates;
	GameView gameView;
	InputManager inputManager;
	UpdateReceiver updateReceiver;
public:
	explicit Client(int,int);
	~Client();
	void main();
	void login();
	void game();
};

#endif
