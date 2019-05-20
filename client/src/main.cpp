#include "../../common/include/real_socket_factory.h"
#include "../../common/include/real_socket.h"
#include "../../common/include/protocolo.h"

#include <iostream>


int main() {
    RealSocket socket = RealSocketFactory::getClientSocket("localhost", "4545");
    Protocolo protocolo(&socket);

    std::cout << protocolo.recvString() << std::endl;

    return 0;
}
