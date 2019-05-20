#include "../include/clientManager.h"
#include "../../common/include/socket.h"

int main() {
	Socket accepterSocket;
	accepterSocket.bindAndListen("4545");	

	ClientManager cm(accepterSocket.accept());
	cm.sendInt(32);

    return 0;
}
