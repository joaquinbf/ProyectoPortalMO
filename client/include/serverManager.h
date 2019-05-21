#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <iostream>
#include <list>

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/action.h"

class ServerManager{
private:
	Protocol protocol;
public:
	explicit ServerManager(const char* address,const char * port);
	~ServerManager();
	void recvInt();
	std::list<Creator> createStage();
	void sendAction(const Action ac);
	//void updateManager();
};

#endif
