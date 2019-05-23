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
        std::cout << "input recv : antes recvAction()" << std::endl;
        Action action = this->protocol->receiveAction();
        std::cout << "input recv : despues recvAction()" << std::endl;


        std::cout << action.getAction() << std::endl;
        this->queue.push(action);
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}

ProtectedQueue<Action> *InputReceiver::getQueue() {
    return &this->queue;
}
