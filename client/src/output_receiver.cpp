#include "../include/output_receiver.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include <iostream>

OutputReceiver::OutputReceiver(Protocol *protocol):
    protocol(protocol),
    keep_running(true) {
}

void OutputReceiver::run() {
    try {
        while (this->keep_running) {
            Update update = this->protocol->receiveUpdate();
            std::cout << "OutputReceiver update recibida: "
                      << update.getCommand() << std::endl;
            this->update_queue.push(update);
        }
    } catch (const ConnectionErrorException &e) {
        std::cout << "Error en OutputReceiver: " << e.what() << std::endl;
    }
}

void OutputReceiver::stop() {
    this->keep_running = false;
    // Pusheo un update falso para avisar a los threads que esten en
    // wait_and_pop (esperando un output de este hilo), que se va a terminar.
    Update update(
        COMMAND::STOP_THREAD_COMMAND,
        ENTITY::NONE_ENTITY,
        0,
        STATUS::NONE_STATUS,
        0,
        0,
        0);
    this->update_queue.push(update);
    this->protocol->shutdownWR();
    this->protocol->close();
}

Update OutputReceiver::waitAndPop() {
    return this->update_queue.wait_and_pop();
}
