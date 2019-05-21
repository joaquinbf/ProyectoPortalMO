#include "../include/player.h"
#include "../include/world.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

Player::Player(Socket &socket, World *world):
    keep_running(true),
    socket(std::move(socket)),
    world(world) {
}

void Player::run() {

}
