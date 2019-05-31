#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../common/include/socket.h"
#include "../include/player.h"

class Game{
private:
	//Stage stage;
	std::vector<Player*> players;
	ProtectedQueue<Action> inputs;
	ProtectedQueue<Update> updates;
	uint32_t capacity;
public:
	Game(); //tendria que haber un constructor que reciba el nombre del mapa
	//y ya lo cargue, pero ahora voy a dejar un mapa harcodeado en el constructor
	~Game();
	void addPlayer(Socket socket);
};

#endif
