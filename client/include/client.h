#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <thread>
#include "../include/chell.h"
#include "../include/serverManager.h"

class Client{
private:
	int x;
	int y;
	bool running;
	Chell* chellPtr;
	ServerManager serverManager;
public:
	Client();
	~Client();
	int main();	
private:
	void inputManager();
};

#endif
