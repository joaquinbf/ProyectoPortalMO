#include "../../../include/bodies/chell/keypad.h"

Keypad::Keypad() {
    keys[KEY::LEFT_KEY] = Key();
    keys[KEY::RIGHT_KEY] = Key();
    keys[KEY::UP_KEY] = Key();
    keys[KEY::DOWN_KEY] = Key();
    keys[KEY::FIRE_KEY] = Key();
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
