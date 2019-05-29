#include "../include/input_receiver.h"
#include "../include/command/command.h"
#include "../include/command/command_factory.h"
#include "../../common/include/thread.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"

InputReceiver::InputReceiver(
    Protocol *protocol,
    ProtectedQueue<Command *> *command_queue):
    keep_running(true),
    protocol(protocol),
    command_queue(command_queue) {
}

void InputReceiver::run() {
    while (this->keep_running) {
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
