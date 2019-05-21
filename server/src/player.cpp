#include "../include/player.h"
#include "../include/world.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

Player::Player(Socket &socket):
    keep_running(true),
    protocol(std::move(socket)) {
}

void Player::run() {

}
