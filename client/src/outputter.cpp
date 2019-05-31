#include "../include/outputter.h"

#include "../include/output_receiver.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include <iostream>

Outputter::Outputter(Protocol *protocol):
    output_receiver(protocol) {
}

void Outputter::run() {
    this->output_receiver.start();
    const int MAX = 10;
    for (int i = 0; i < MAX; i++) {
        Update update = this->output_receiver.waitAndPop();
        std::cout << "Update poppeada: " << update.getCommand()
                  << std::endl;
        if (update.getCommand() == STOP_THREAD_COMMAND) {
            break;
        }
    }
}

void Outputter::stop() {
    this->output_receiver.stop();
    this->output_receiver.join();
}
