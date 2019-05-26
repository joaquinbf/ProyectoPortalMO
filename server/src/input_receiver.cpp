#include "../include/input_receiver.h"
#include <iostream>

InputReceiver::InputReceiver(Protocol *protocol):
    keep_running(true),
    protocol(protocol) {
}

void InputReceiver::run() {
    CommandFactory cf;
    try {
        std::cout << "corriendo en input receiver" << std::endl;
        this->keep_running = true;
        while (this->keep_running) {
            std::cout << "input recv : antes recvAction()" << std::endl;
            Action action = this->protocol->receiveAction();
            std::cout << "input recv : despues recvAction()" << std::endl;

            Command *command = cf.create(action);
            this->queue.push(command);
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}

ProtectedQueue<Command *> *InputReceiver::getQueue() {
    return &this->queue;
}
