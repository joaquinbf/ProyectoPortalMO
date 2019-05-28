#include "../include/player.h"

Player::Player(Socket socket, Chell *chell):
    socket(std::move(socket)),
    chell(chell) {
}
