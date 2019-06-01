#include "../../../include/bodies/chell/keypad.h"

Keypad::Keypad() {
    keys[KEY::LEFT] = Key();
    keys[KEY::RIGHT] = Key();
    keys[KEY::UP] = Key();
    keys[KEY::DOWN] = Key();
    keys[KEY::FIRE] = Key();
}

void Keypad::press(KEY k) {
    this->keys[k].press();
}

void Keypad::release(KEY k) {
    this->keys[k].release();
}

double Keypad::elapsedTimeBeingPressed(KEY k) {
    return this->keys[k].elapsedTimeBeingPressed();
}
