#include "../include/update_sender.h"

UpdateSender::UpdateSender(Protocol *protocol):
    keep_running(true),
    protocol(protocol) {
}

void UpdateSender::run() {
    try {
        std::cout << "corriend update sender" << std::endl;
        while (this->keep_running) {
            Update update = this->queue.wait_and_pop();
            std::cout << "pre: send update" << std::endl;
            this->protocol->sendUpdate(update);
            std::cout << "post: send update" << std::endl;
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void UpdateSender::stop() {
    this->keep_running = false;
}

ProtectedQueue<Update> *UpdateSender::getQueue() {
    return &this->queue;
}
