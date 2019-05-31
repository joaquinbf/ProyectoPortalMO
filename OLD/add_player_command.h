#ifndef __ADD_PLAYER_COMMAND_H__
#define __ADD_PLAYER_COMMAND_H__

#include "command.h"

class Player;
class World;

class AddPlayerCommand: public Command {
private:
    Player *player;

public:
    AddPlayerCommand(Player *player);
    virtual void execute(World *world) override;
};

#endif
