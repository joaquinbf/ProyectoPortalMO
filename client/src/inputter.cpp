#include "../include/inputter.h"

#include "../include/input_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include <iostream>

Inputter::Inputter(Protocol *protocol):
    input_sender(protocol) {
}

void Inputter::run() {
    this->input_sender.start();
    const int MAX = 10;
    for (int i = 0; i < MAX; i++) {
        Action action(ACTION::FIRE, 0);
        std::cout << "Action pusheada: " << action.getAction()
                  << std::endl;
        this->input_sender.push(action);
    }
}

void Inputter::stop() {
    this->input_sender.stop();
    this->input_sender.join();
}
