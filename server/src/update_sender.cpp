#include "../include/update_sender.h"

UpdateSender::UpdateSender():
    keep_running(true) {
}

void UpdateSender::run() {
    this->keep_running = true;
    while (this->keep_running) {
    }
}

void UpdateSender::stop() {
    this->keep_running = false;
}

ProtectedQueue<Update> *UpdateSender::getUpdateQueue() {
    return &this->update_queue;
}
