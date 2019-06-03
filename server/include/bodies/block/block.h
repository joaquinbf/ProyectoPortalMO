#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../body.h"
#include "shape.h"
#include "material.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"

#include <cstdint>

class Shape;
class SquareShape;
class DiagonalShape;

class Material;
class MetalMaterial;
class StoneMaterial;

class Chell;
class Button;
class Gate;
class Rock;

class Block: public Body {
private:
    Shape *shape;
    Material *material;
    const float HALF_WIDTH = 100;
    const float HALF_HEIGHT = 100;
    const float DENSITY = 1;
    const float ANGLE = 0;

public:
    /* Instancia un block de id 'body_id' sobre b2world en la posicion (x, y)
     * de shape y material asignado.
     * Al liberarse el block tambien se libera shape y material. */
    Block(uint32_t body_id, b2World *b2world,
          float x, float y,
          Shape *shape, Material *material);

    /* Libera los recursos utilizados */
    ~Block();

    /* Devuelve una update del bloque */
    virtual Update createUpdate(COMMAND command) const;

    virtual void handleBeginContactWith(Body *other_body) override;

    virtual void letBeginContactBeHandledBy(Chell *chell) override;

    virtual void letBeginContactBeHandledBy(Block *block) override;

    virtual void letBeginContactBeHandledBy(Button *button) override;

    virtual void letBeginContactBeHandledBy(Gate *gate) override;

    virtual void letBeginContactBeHandledBy(Rock *rock) override;
};

#endif
