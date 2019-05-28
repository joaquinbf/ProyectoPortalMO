#include "../include/add_player_command.h"
#include "../include/world.h"
#include "../include/body.h"


AddPlayerCommand::AddPlayerCommand(Player *player):
    player(player) {
}


void AddPlayerCommand::execute(World *world) {
    world->addPlayer(this->player);
    this->player->sendChellIdToClient();
    std::vector<Body *> bodies = world->getBodyList();
    for (Body *body: bodies) {
        Update update = body->getCreateUpdate();
        this->player->sendUpdate(update);
    }
}
