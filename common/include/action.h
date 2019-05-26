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
    FIRE,
    JIG
};

class Action{
private:
	ACTION action;
	uint32_t param;

public:
    Action();
	explicit Action(ACTION ac,uint32_t param);
	~Action();
	ACTION getAction() const;
	uint32_t getParam() const;
};

#endif
