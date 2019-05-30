#include "../include/broadcaster.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"
#include "../../common/include/thread.h"

void Broadcaster::run() {
    while (this->keep_running) {
        Update update = this->update_queue->wait_and_pop();
        this->handleUpdate(update);
    }
}

void Broadcaster::stop() {
    Update stop_broadcast_update(
        COMMAND::STOP_BROADCASTER_COMMAND,
        ENTITY::NONE_ENTITY,
        0,
        STATUS::NONE_STATUS,
        0,
        0,
        0);
    this->update_queue->push(stop_broadcast_update);
}

void Broadcaster::handleUpdate(const Update &update) {
    switch (update.getCommand()) {
        case COMMAND::STOP_BROADCASTER_COMMAND:
            this->keep_running = false;
            break;
        default:
            break;
    }
}
