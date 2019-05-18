#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"

class Character {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 1;
    const float HALF_HEIGHT = 2;
    const float DENSITY = 1;
    const float ANGLE = 0;

public:
    /* Instancia un character de 4x2 metros con su centro en la
     * posicion (x, y) de world. */
    Character(b2World *b2world, float x, float y);

    /* Camina a la izquierda */
    void walkLeft();

    /* Camina  ala derecha */
    void walkRight();

    /* Salta */
    void jump();
};

#endif
