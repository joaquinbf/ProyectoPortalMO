#include "../include/input_receiver.h"
#include <iostream>

InputReceiver::InputReceiver(Protocol *protocol):
    keep_running(true),
    protocol(protocol) {
}

void InputReceiver::run() {
    std::cout << "corriendo en input receiver" << std::endl;
    this->keep_running = true;
    while (this->keep_running) {
        Action action = this->protocol->receiveAction();
        std::cout << action.getAction() << std::endl;
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
