#include "../include/input_receiver.h"


InputReceiver::InputReceiver(
    Player *player,
    ProtectedQueue<Command *> *commands):
    player(player),
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
