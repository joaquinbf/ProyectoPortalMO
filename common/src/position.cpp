#include "../include/position.h"

Position::Position(float x, float y): x(x), y(y) {
}

float Position::getX() {
    return this->x;
}

float Position::getY() {
    return this->y;
}
