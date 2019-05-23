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

class Client{
private:
	int resx;
	int resy;
	SdlWindow window;
	Chell* myChell;
	bool running;
	float scale;
	ServerManager serverManager;
	std::map<uint32_t,Entity *> entities;
public:
	explicit Client(int,int);
	~Client();
	void main();
private:
	void inputManager();
	void zoomIn();
	void zoomOut();
};

#endif
