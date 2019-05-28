#ifndef __COMMAND_H__
#define __COMMAND_H__

class World;

class Command {
public:
    virtual void execute(World *world) = 0;
    virtual ~Command();
};

#endif
