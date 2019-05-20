#include "../include/server.h"

int Server::main() {
    RealSocketFactory rsf;
    RealSocket socket = rsf.getServerSocket("4545");
    socket.listen(100);

    RealSocket peer = socket.accept();

    

    return 0;
}
