#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <iostream>

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"

class ServerManager{
private:
	RealSocket socket;
public:
	explicit ServerManager(const char* addres,const char * port);
	~ServerManager();
	void recvInt();
	
};

#endif
