#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <thread>
#include "../include/chell.h"

class Client{
private:
	int x;
	int y;
	bool running;
	Chell* chellPtr;
public:
	Client();
	~Client();
	int main();	
private:
	void eventManager();
};

#endif
