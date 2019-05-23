#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <thread>
#include <cstdint>
#include <map>

#include "../include/chell.h"
#include "../include/serverManager.h"
#include "../include/SdlWindow.h"
#include "../include/entityFactory.h"
#include "../../common/include/entity.h"
#include "../../common/include/creatorMessage.h"
#include "../../common/include/update.h"
#include "../../common/include/protected_queue.h"

class Client{
private:
	int resx;
	int resy;
	SdlWindow window;
	Chell* myChell;
	uint32_t myChellId;
	bool running;
	float scale;
	ServerManager serverManager;
	std::map<uint32_t,Entity *> entities;
	ProtectedQueue<Update> updates;
public:
	explicit Client(int,int);
	~Client();
	void main();
private:
	void inputManager();
	void updateReceiver();
	void updateHandler(Update update);
	void zoomIn();
	void zoomOut();
};

#endif
