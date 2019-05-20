#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include "../../common/include/real_socket_factory.h"
#include "../../common/include/real_socket.h"
#include "../../common/include/protocolo.h"

class ServerManager{
	RealSocket socket;
	Protocolo protocol;
public:
	explicit ServerManager(const char * adress, const char * port);
	~ServerManager();
	
};


#endif
