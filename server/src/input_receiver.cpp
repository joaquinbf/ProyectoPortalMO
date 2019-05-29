#include "../include/input_receiver.h"
#include "../include/command/command.h"
#include "../include/command/command_factory.h"
#include "../../common/include/thread.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/exceptions.h"

// TODO: eliminar
#include <iostream>


InputReceiver::InputReceiver(
    Protocol *protocol,
    ProtectedQueue<Command *> *command_queue):
    keep_running(true),
    protocol(protocol),
    command_queue(command_queue) {
}

void InputReceiver::run() {
    CommandFactory cf;
    try {
        std::cout << __func__ << std::endl;
        while (this->keep_running) {
            Action action = this->protocol->receiveAction();
            Command *command = cf.createCommand(action);
            this->command_queue->push(command);
            delete command;
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
    this->protocol->close();
}
