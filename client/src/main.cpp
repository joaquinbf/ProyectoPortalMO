#include "../include/client.h"

// TODO: eliminar
#include "../../common/include/socket.h"
#include "../../common/include/port.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include "../../common/include/update.h"
#include "../../common/include/thread.h"
#include <vector>
#include <chrono>
#include <thread>

void contactServer();

class Input: public Thread {
private:
	bool keep_running;
	Protocol *protocol;

public:
	Input(Protocol *protocol):
		keep_running(true),
		protocol(protocol) {}

	virtual void run() override {
		try {
			while (this->keep_running) {
				Action action(ACTION::JUMP, 0);
				this->protocol->sendAction(action);
				std::cout << "ACTION SEND: "
						 << action.getAction() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		} catch (const ConnectionErrorException &e) {
		}
		std::cout << "FUERA DEL WHILE INPUT: "  << std::endl;
	}

	void stop() {
		this->keep_running = false;
		this->protocol->shutdownWR();
	}
};

class Updater: public Thread {
private:
	bool keep_running;
	Protocol *protocol;

public:
	Updater(Protocol *protocol):
		keep_running(true),
		protocol(protocol) {}

	virtual void run() override {
		try {
			while (this->keep_running) {
				Update update = this->protocol->receiveUpdate();
				std::cout << "UPDATE : " << update.getCommand() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		} catch (const ConnectionErrorException &e) {
		}
		std::cout << "FUERA DEL WHILE UPDATE : " <<  std::endl;

	}

	void stop() {
		this->keep_running = false;
		this->protocol->shutdownRD();
	}
};

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

	Input input(&protocol);
	input.start();
	Updater updater(&protocol);
	updater.start();

	const char QUIT = 'q';
	while (std::cin.get() != QUIT) {
	}

	protocol.close();
	input.stop();
	input.join();
	updater.stop();
	updater.join();

	std::cout << "fin client" << std::endl;
}
