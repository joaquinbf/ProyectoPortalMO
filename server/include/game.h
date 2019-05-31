#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include <string>

#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../common/include/socket.h"
#include "../include/player.h"
#include "../include/stage.h"
#include "../include/broadcaster.h"

class Game{
private:
	Stage stage;
	std::vector<Player*> players;
	ProtectedQueue<Action> inputs;
	ProtectedQueue<Update> updates;
	Broadcaster broadcaster;
	uint32_t capacity;
public:
	explicit Game(const std::string& mapName); 
	~Game();
	void addPlayer(Socket socket);
};

#endif
