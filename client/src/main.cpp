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

	Inputter inputter(&protocol);
	Outputter outputter(&protocol);

	inputter.start();
	outputter.start();

	const char QUIT = 'q';
	while (std::cin.get() != QUIT) {
	}


	// Con esto se podria lanzar ConnectionErrorException en 3 threads!
	// 1. Este thread: porque es el duenio del socket y podria
	//                 estar bloqueado el socket en un send() o recv()
	// 2. InputSender: porque podria estar bloqueado en send().
	// 3. OutputReceiver: porque podria estar bloqueado en recv().

	// Setteo keep_running = false en los threads y
	inputter.stop();
	outputter.stop();

	inputter.join();
	outputter.join();
}
