#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "key.h"
#include <map>

enum KEY {
    LEFT_KEY = 0,
    RIGHT_KEY,
    UP_KEY,
    DOWN_KEY,
    FIRE_KEY
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
