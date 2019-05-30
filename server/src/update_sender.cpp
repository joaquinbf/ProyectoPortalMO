#include "../include/update_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include "../../common/include/exceptions.h"

// TODO: borrar
#include <iostream>

UpdateSender::UpdateSender(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void UpdateSender::run() {
    std::cout << "void UpdateSender::run()" << std::endl;
    this->keep_running = true;
    try {
        while (this->keep_running) {
            Update update = this->update_queue.wait_and_pop();
            this->protocol->sendUpdate(update);
        }
    } catch (const ConnectionErrorException &e) {
    }

}

void UpdateSender::stop() {
    this->keep_running = false;
}

ProtectedQueue<Update> *UpdateSender::getUpdateQueue() {
    return &this->update_queue;
}
