#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <thread>
#include <cstdint>
#include <map>
#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <exception>
#include <list>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/entityFactory.h"
#include "../include/serverManager.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/inputManager.h"
#include "../include/updateReceiver.h"
#include "../include/textureManager.h"
#include "../include/background.h"

#include "../../common/include/port.h"
#include "../../common/include/entity.h"
#include "../../common/include/update.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/types.h"

class Client{
private:
	int resx;
	int resy;
	SdlWindow window;
	Chell* myChell;
	uint32_t myChellId;
	bool running;
	float scale;
	TextureManager textureManager;
	ServerManager serverManager;
	std::map<uint32_t,Entity *> entities;
	ProtectedQueue<Update> updates;
	InputManager inputManager;
	UpdateReceiver updateReceiver;
public:
	explicit Client(int,int);
	~Client();
	void main();
	void zoomIn();
	void zoomOut();
private:
	void updateHandler(Update update);
	
};

#endif
