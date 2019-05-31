#include "../include/input_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include <iostream>

InputSender::InputSender(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void InputSender::run() {
    try {
        while (this->keep_running) {
            Action action = this->action_queue.wait_and_pop();
            std::cout << "InputSender accion para enviar: "
                      << action.getAction() << std::endl;
            if (action.getAction() == STOP_THREAD) {
                this->keep_running = false;
            } else {
                this->protocol->sendAction(action);
            }

        }
    } catch (const ConnectionErrorException &e) {
        std::cout << "Error en InputSender: " << e.what() << std::endl;
    }
}

void InputSender::stop() {
    this->protocol->shutdownRD();
    this->protocol->close();

    this->keep_running = false;
    // Pusheo una accion solo para despertar al thread de wait_and_pop
    Action wake_thread_action(ACTION::STOP_THREAD, 0);
    this->action_queue.push(wake_thread_action);
}

void InputSender::push(const Action &action) {
    this->action_queue.push(action);
}
