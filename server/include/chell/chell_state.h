#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

class Chell;

class ChellState {
private:
    Chell *chell;
public:
    virtual ~ChellState();
    Chell *getChell();
    virtual void keyLeft() = 0;
};

#endif
