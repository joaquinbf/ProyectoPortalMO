#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__

#include "../../common/include/real_socket_factory.h"
#include "../../common/include/real_socket.h"
#include "../../common/include/protocolo.h"

class ClientManager {
private:
    RealSocket socket;
public:
    ClientManager(const char *node);
    void sendInt();
};

#endif
