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
            switch (update.getCommand()) {
                case STOP_UPDATE_SENDER_COMMAND:
                    this->keep_running = false;
                    break;
                default:
                    this->protocol->sendUpdate(update);
                    break;
            }
        }
    } catch (const ConnectionErrorException &e) {
    }

}

void UpdateSender::stop() {
    this->keep_running = false;
    Update update(
        COMMAND::STOP_UPDATE_SENDER_COMMAND,
        ENTITY::NONE_ENTITY,
        0,
        STATUS::NONE_STATUS,
        0,
        0,
        0);
    this->update_queue.push(update);
}

ProtectedQueue<Update> *UpdateSender::getUpdateQueue() {
    return &this->update_queue;
}
