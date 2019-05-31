#ifndef _BROADCASTER_H_
#define _BROADCASTER_H_

#include <list>
#include <unistd.h>

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"

class Broadcaster : public Thread{
private:
	bool running;
	ProtectedQueue<Update>* source;
	std::list<ProtectedQueue<Update>*> clients;
public:
	explicit Broadcaster(ProtectedQueue<Update>* source);
	~Broadcaster();
	void addPlayer(ProtectedQueue<Update>* client);
	virtual void run() override;
    void stop();	
};

#endif
