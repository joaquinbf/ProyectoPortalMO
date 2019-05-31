#ifndef _STAGE_H_
#define _STAGE_H_

#include <vector>
#include <string>
#include <list>

#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"

class Stage{
private:
	ProtectedQueue<Action>* inputs;
	ProtectedQueue<Update>* updates;
public:
	explicit Stage(const std::string& mapName,ProtectedQueue<Action>* inputs,
		ProtectedQueue<Update>* updates);
	~Stage();
	uint32_t getCapacity() const;
	std::list<Update> getNewPlayerUpdates()const;	
};

#endif
