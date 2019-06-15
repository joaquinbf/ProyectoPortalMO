#include "../include/math_ext.h"

b2Vec2 MathExt::reflect(b2Vec2 n, b2Vec2 v) {
    b2Vec2 r = v - (1/n.LengthSquared())*(2*(v*n)*n);
    return r;
}

float operator*(const b2Vec2& v, const b2Vec2& u) {
    return (v.x * u.x) + (v.y * u.y);
}
