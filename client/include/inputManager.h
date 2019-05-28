#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include <SDL2/SDL.h>

#include "../include/serverManager.h"
#include "../../common/include/action.h"
#include "../../common/include/thread.h"

class InputManager : public Thread{
private:
	const ServerManager& serverManager;
	bool running;
public:
	explicit InputManager(const ServerManager& sm);
	~InputManager();
	virtual void run() override;
    void stop();
    bool isRunning() const;
};

#endif
