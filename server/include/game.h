#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include <string>

#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../common/include/socket.h"
#include "../../common/include/gameInfo.h"
#include "../include/player.h"
#include "../include/stage.h"
#include "../include/broadcaster.h"

class Game{
private:
	static uint32_t id;
	Stage stage;
	std::vector<Player*> players;
	ProtectedQueue<Action> inputs;
	ProtectedQueue<Update> updates;
	Broadcaster broadcaster;
	GameInfo gameInfo;
public:
	explicit Game(const std::string& mapName); 
	~Game();
	void addPlayer(Player* player);
	const GameInfo& getGameInfo();
};

uint32_t Game::id = 0;

#endif
