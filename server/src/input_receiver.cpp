#include "../include/input_receiver.h"

void InputReceiver::run() {
    this->keep_running = true;
    while (this->keep_running) {
        
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
