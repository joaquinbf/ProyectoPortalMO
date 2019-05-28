#include "../include/input_receiver.h"


InputReceiver::InputReceiver(
    Protocol *protocol,
    ProtectedQueue<Command> *commands):
    protocol(protocol),
    commands(commands) {
}

void InputReceiver::run() {
    this->keep_running = true;
    while (this->keep_running) {
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
