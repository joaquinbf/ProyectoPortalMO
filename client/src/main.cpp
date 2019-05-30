#include "../include/client.h"

// TODO: eliminar
#include "../../common/include/socket.h"
#include "../../common/include/port.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
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

	std::vector<Action> actions;
	actions.emplace_back(ACTION::JUMP, 0);
	actions.emplace_back(ACTION::JUMP, 0);
	actions.emplace_back(ACTION::JUMP, 0);
	actions.emplace_back(ACTION::QUIT, 0);

	for (const Action &action: actions) {
		protocol.sendAction(action);
	}
}
