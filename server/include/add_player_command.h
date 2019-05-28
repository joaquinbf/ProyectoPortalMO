#ifndef __ADD_PLAYER_COMMAND_H__
#define __ADD_PLAYER_COMMAND_H__

#include "command.h"
#include "player.h"

class Player;

class AddPlayerCommand: public Command {
private:
    Player *player;

public:
    AddPlayerCommand(Player *player);
    virtual void execute() override;
};

#endif
