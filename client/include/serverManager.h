#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <iostream>

#include "../../common/include/real_socket_factory.h"
#include "../../common/include/real_socket.h"
#include "../../common/include/protocolo.h"

class ServerManager{
private:
	RealSocket socket;
public:
	explicit ServerManager(const char* addres,const char * port);
	~ServerManager();
	void recvInt();
	
};

#endif
