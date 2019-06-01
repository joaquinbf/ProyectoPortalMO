#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "key.h"
#include <map>

enum KEY {
    LEFT ,
    RIGHT,
    UP,
    DOWN,
    FIRE,
};

class Keypad {
private:
    std::map<KEY, Key> keys;

public:
    Keypad();
    void press(KEY k);
    void release(KEY k);
    double elapsedTimeBeingPressed(KEY k);
};

#endif
