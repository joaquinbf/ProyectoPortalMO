#include "../include/output_receiver.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"

OutputReceiver::OutputReceiver(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void OutputReceiver::run() {
    try {
        while (this->keep_running) {
            Update update = this->protocol->receiveUpdate();
            this->update_queue.push(update);
        }
    } catch (const ConnectionErrorException &e) {
    }
}

void OutputReceiver::stop() {
    this->keep_running = false;
}

Update OutputReceiver::waitAndPop() {
    return this->update_queue.wait_and_pop();
}
