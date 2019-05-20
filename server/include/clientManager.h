#ifndef _CLIENT_MANAGER_H_
#define _CLIENT_MANAGER_H_

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"

class ClientManager{
private: 
	Protocol protocol;
public:
	explicit ClientManager(Socket);
	~ClientManager();
	void sendInt(uint32_t);	
};

#endif
