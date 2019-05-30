#include "../include/broadcaster.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"
#include "../../common/include/thread.h"

Broadcaster::Broadcaster(ProtectedQueue<Update> *update_queue):
    update_queue(update_queue) {
}

void Broadcaster::run() {
    while (this->keep_running) {
        Update update = this->update_queue->wait_and_pop();
        this->handleUpdate(update);
    }
}

void Broadcaster::stop() {
    const uint32_t NONE_ID_OBJECT = 0;
    const int32_t NONE_POSX = 0;
    const int32_t NONE_POSY = 0;
    const uint32_t NONE_DIRECTION = 0;

    Update stop_broadcast_update(
        COMMAND::STOP_BROADCASTER_COMMAND,
        ENTITY::NONE_ENTITY,
        NONE_ID_OBJECT,
        STATUS::NONE_STATUS,
        NONE_POSX,
        NONE_POSY,
        NONE_DIRECTION);
    this->update_queue->push(stop_broadcast_update);
}

void Broadcaster::handleUpdate(const Update &update) {
    switch (update.getCommand()) {
        case COMMAND::STOP_BROADCASTER_COMMAND:
            this->keep_running = false;
            break;
        default:
        this->updatePlayerQueues(update);
            break;
    }
}

void Broadcaster::addPlayerUpdateQueue(
    ProtectedQueue<Update> *player_update_queue) {
    this->player_update_queues.push_back(player_update_queue);
}

void Broadcaster::updatePlayerQueues(const Update &update) {
    for (ProtectedQueue<Update> *queue: this->player_update_queues) {
        queue->push(update);
    }
}
