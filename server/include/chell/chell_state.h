#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

class Chell;

class ChellState {
private:
    Chell *chell;
public:
    ChellState(Chell *chell);
    virtual ~ChellState();
    Chell *getChell();
    virtual void keyLeft() = 0;
    virtual void keyRight() = 0;
    virtual void keyJump() = 0;
    virtual void stopKeyLeft() = 0;
};

#endif
