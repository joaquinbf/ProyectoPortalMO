#ifndef _INPUT_RECEIVER_H_
#define _INPUT_RECEIVER_H_

#include "../../common/include/thread.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"

class Game;

class InputReceiver : public Thread{
private: 
	bool running;
	Protocol& protocol;
	ProtectedQueue<Action>* inputPtr;
	Game* game;
public:
	explicit InputReceiver(Protocol& p);
	void setGamePtr();
	~InputReceiver();
    virtual void run() override;
    void stop();	
    void setInputPtr(ProtectedQueue<Action>* ptr);
};

#endif
