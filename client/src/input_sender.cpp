#include "../include/input_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"

InputSender::InputSender(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void InputSender::run() {
    try {
        while (this->keep_running) {
            Action action = this->action_queue.wait_and_pop();
            this->protocol->sendAction(action);
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void InputSender::stop() {
    this->keep_running = false;
}

void InputSender::push(const Action &action) {
    this->action_queue.push(action);
}
