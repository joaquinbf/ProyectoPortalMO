#include "../include/add_player_command.h"
#include "../include/world.h"

AddPlayerCommand::AddPlayerCommand(Player *player):
    player(player) {
}


void AddPlayerCommand::execute(World *world) {
    world->addPlayer(this->player);
    this->player->sendChellIdToClient();
}
