#include "../../common/include/real_socket_factory.h"
#include "../../common/include/real_socket.h"
#include "../../common/include/protocolo.h"

int main() {
    RealSocket socket = RealSocketFactory::getServerSocket("4545");
    socket.listen(100);

    RealSocket peer = socket.accept();
    Protocolo protocolo(&peer);

    protocolo.sendString("hola");

    return 0;
}
