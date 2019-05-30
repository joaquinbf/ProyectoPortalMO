#include "../include/client.h"

// TODO: eliminar
#include "../../common/include/socket.h"
#include "../../common/include/port.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include "../../common/include/update.h"
#include <vector>

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
	Protocol protocol(std::move(socket));

	// for (int i = 0; i < 5; i++) {
	// 	Action action(ACTION::JUMP, 0);
	// 	protocol.sendAction(action);
	// }

	for (int i = 0; i < 10; i++) {
		Update update = protocol.receiveUpdate();
		std::cout << update.getCommand() << std::endl;
	}
	protocol.shutdownWR();
}
