#ifndef _STAGE_H_
#define _STAGE_H_

#include <vector>
#include <string>
#include <list>
#include <unistd.h>

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../include/world.h"
#include "../include/serializer.h"

class Stage : public Thread {
private:
	bool running;
	World world;
	ProtectedQueue<Action>* inputs;
	ProtectedQueue<Update>* updates;
	const std::string MAP_PATH = "../maps";

public:
	explicit Stage(const std::string& mapName,ProtectedQueue<Action>* inputs,
		ProtectedQueue<Update>* updates);
	~Stage();
    virtual void run() override;
    void stop();
	std::list<uint32_t> getChellsIdList() const;
	std::list<Update> getNewPlayerUpdates()const;
};

#endif
