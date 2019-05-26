#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

class Chell;

class ChellState {
private:
    Chell *chell;
public:
    ChellState(Chell *chell);
    Chell *getChell();
    virtual ~ChellState();
    virtual void runLeft() = 0;
};

#endif
