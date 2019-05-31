#include "../include/add_player_command.h"
#include "../include/world.h"
#include "../include/body.h"

#include <iostream>

AddPlayerCommand::AddPlayerCommand(Player *player):
    player(player) {
}


void AddPlayerCommand::execute(World *world) {
    std::cout << "execute run" << std::endl;
    world->addPlayer(this->player);
    this->player->sendChellIdToClient();
    std::cout << "send chell id to client" << std::endl;
    std::vector<Body *> bodies = world->getBodyList();
    std::cout << "get body list" << std::endl;
    for (Body *body: bodies) {
        std::cout << "ptr body" << body <<  std::endl;
        Update update = body->getCreateUpdate();
        this->player->sendUpdate(update);
    }
    std::cout << "saliendo execute" <<   std::endl;

}
