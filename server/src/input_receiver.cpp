#include "../include/input_receiver.h"

InputReceiver::InputReceiver(
    Protocol *protocol,
    ProtectedQueue<Command *> *commands):
    protocol(protocol),
    commands(commands),
    keep_running(true) {
}

void InputReceiver::run() {
    while (this->keep_running) {

    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
