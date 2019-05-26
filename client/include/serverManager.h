#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <iostream>
#include <list>

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/action.h"
<<<<<<< Updated upstream
#include "../../common/include/creatorMessage.h"
=======
#include "../../common/include/creatorMesage.h"
>>>>>>> Stashed changes
#include "../../common/include/update.h"

class ServerManager{
private:
	Protocol protocol;
public:
	explicit ServerManager(const char* address,const char * port);
	~ServerManager();
	void stop();
	std::list<CreatorMessage> receiveStage();
	void sendAction(const Action ac);
	Update receiveUpdate();
};

#endif
