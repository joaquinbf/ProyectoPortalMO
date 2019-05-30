#include "../include/update_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include "../../common/include/exceptions.h"

UpdateSender::UpdateSender(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void UpdateSender::run() {
    this->keep_running = true;
    try {
        while (this->keep_running) {
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
