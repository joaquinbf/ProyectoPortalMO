#ifndef __SERVER_H__
#define __SERVER_H__

#include "../../common/include/socket.h"
#include "../include/accepter.h"

#define PORT "4545"

class Server {
private:
    Socket socket;
public:
    Server();
    int main();
};

#endif
