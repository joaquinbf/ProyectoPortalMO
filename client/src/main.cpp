#include "../include/client.h"

// TODO: borrar, es solo de juguete mientras pruebo la conexion
//	     con el server.
#include "../include/inputter.h"
#include "../include/outputter.h"
#include "../../common/include/port.h"
#include "../../common/include/protocol.h"
#include <iostream>

void toyClient();

int main() {
	// try{
	// 	Client client(800,600);
	//     client.main();
    // } catch (std::exception& e) {
    //     std::cout << e.what() << std::endl;
    //     return 1;
    // }
	// return 0;
	toyClient();
	return 0;
}

void toyClient() {
	Socket socket;
	socket.connect("localhost", PORT);
	Protocol protocol(std::move(socket));

	// En inputter debe estar la logica de enviar el input del teclado.
	Inputter inputter(&protocol);
	// En output deberia estar la logica del render.
	Outputter outputter(&protocol);

	inputter.start();
	outputter.start();

	const char QUIT = 'q';
	while (std::cin.get() != QUIT) {
	}

	inputter.stop();
	outputter.stop();

	inputter.join();
	outputter.join();
}
