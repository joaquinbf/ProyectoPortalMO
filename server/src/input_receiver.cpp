#include "../include/input_receiver.h"


InputReceiver::InputReceiver(
    Chell *chell,
    Protocol *protocol,
    ProtectedQueue<Command *> *commands):
    chell(chell),
    protocol(protocol),
    commands(commands) {
}

void InputReceiver::run() {
    this->keep_running = true;
    while (this->keep_running) {
        Command *command;
        Action action = this->protocol->receiveAction();

        switch (action.getAction()) {
            case ACTION::RUN_LEFT:
                command = new LeftCommand(this->chell);
                break;
            default:
                command = new DefaultCommand();
                break;
        }

        this->commands->push(command);
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
