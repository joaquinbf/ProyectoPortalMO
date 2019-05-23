#include "../include/update_sender.h"

UpdateSender::UpdateSender(Protocol *protocol):
    keep_running(true),
    protocol(protocol) {
}

void UpdateSender::run() {
    std::cout << "corriend update sender" << std::endl;
    while (this->keep_running) {
        Update update;
        while (this->queue.try_pop(update)) {
            std::cout << "pre: send update" << std::endl;
            this->protocol->sendUpdate(update);
            std::cout << "post: send update" << std::endl;

        }
    }
}

void UpdateSender::stop() {
    this->keep_running = false;
}

ProtectedQueue<Update> *UpdateSender::getQueue() {
    return &this->queue;
}
