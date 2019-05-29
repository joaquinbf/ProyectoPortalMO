#include "../include/client.h"

// TODO: eliminar
#include "../../common/include/socket.h"
#include "../../common/include/port.h"


void contactServer();

int main() {
	// try{
	// 	Client client(800,600);
	//     client.main();
    // } catch (std::exception& e) {
    //     std::cout << e.what() << std::endl;
    //     return 1;
    // }
	// return 0;
	contactServer();
	return 0;
}

void contactServer() {
	Socket socket;
	socket.connect("localhost", PORT);
}
