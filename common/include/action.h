#ifndef __ACTION_H__
#define __ACTION_H__

#include <cstdint>

enum ACTION: uint8_t {
    QUIT,
    JUMP,
    RUN_LEFT,
    RUN_RIGHT,
    STOP_LEFT,
    STOP_RIGHT,
    JIG,
    FIRE1,
    FIRE2,
    PING    
};

class Action{
private:
    uint32_t id;
	ACTION action;
	uint32_t param;

public:
    Action();
	explicit Action(uint32_t id,ACTION ac,uint32_t param);
	~Action();
    uint32_t getId() const;
	ACTION getAction() const;
	uint32_t getParam() const;
};

#endif
