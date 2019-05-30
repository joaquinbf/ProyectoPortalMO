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
    command_queue(command_queue),
    is_finished(false) {
}

void InputReceiver::run() {
    this->is_finished = false;
    CommandFactory cf;
    try {
        std::cout << __func__ << std::endl;
        while (this->keep_running) {
            Action action = this->protocol->receiveAction();
            this->handleAction(action);
        }
    } catch (const ConnectionErrorException &e) {
    }
    this->is_finished = true;
}

void InputReceiver::stop() {
    this->keep_running = false;
    this->protocol->close();
}

bool InputReceiver::isFinished() {
    return this->is_finished;
}

void InputReceiver::handleAction(const Action &action) {
    switch (action.getAction()) {
        case ACTION::QUIT:
            this->keep_running = false;
            break;
        default: {
            std::cout << "Creacion de command en input recv"
                      << std::endl;
            Command *command = cf.createCommand(action);
            this->command_queue->push(command);
            break;
        }
    }
}
