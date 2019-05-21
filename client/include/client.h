#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <thread>
#include "../include/chell.h"
#include "../include/serverManager.h"

class Client{
private:
	int resx;
	int resy;
	bool running;
	float scale;
	ServerManager serverManager;
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
