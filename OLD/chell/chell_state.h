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
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void up() = 0;
    virtual void stopLeft() = 0;
    virtual void stopRight() = 0;
};

#endif
