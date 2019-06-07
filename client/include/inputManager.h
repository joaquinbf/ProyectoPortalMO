#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include <SDL2/SDL.h>

#include "../include/serverManager.h"
#include "../include/gameView.h"
#include "../include/videoRecorder.h"

#include "../../common/include/action.h"
#include "../../common/include/thread.h"
#include "../../common/include/key.h"
#include "../../common/include/keypad.h"

class InputManager : public Thread{
private:
	bool running;
	const ServerManager& serverManager;
	uint32_t chellId;
	GameView& gameView;
	VideoRecorder& videoRecorder;
	Keypad keypad;
public:
	explicit InputManager(const ServerManager& sm,GameView& g,VideoRecorder& vr);
	~InputManager();
	virtual void run() override;
    void stop();
    bool isRunning() const;

private:
	void pauseMode(const SDL_Event& ev);
	void gameMode(const SDL_Event& ev);
	/* Envia una accion al servidor indicando que una tecla fue presionada. */
	void sendPressAction(Key *key, ACTION action);

	/* Envia una accion al servidor indicando que una tecla fue soltada */
	void sendReleaseAction(Key *key, ACTION action);
};

#endif
