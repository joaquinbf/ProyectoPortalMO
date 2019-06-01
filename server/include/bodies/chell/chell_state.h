#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

class Chell;

class ChellState {
protected:
    Chell *chell;

public:
    ChellState(Chell *chell);
    virtual void pressLeft() = 0;
    virtual void releaseLeft() = 0;
};

#endif
