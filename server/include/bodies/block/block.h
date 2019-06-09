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

class World;

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
class Bullet;

class Block: public Body {
private:
    Shape *shape;
    Material *material;
    const float HALF_WIDTH = 1.00;
    const float HALF_HEIGHT = 1.00;
    const float DENSITY = 1;
    const float ANGLE = 0;
    const float FRICTION = 0.5;

public:
    /* Instancia un block de id 'body_id' sobre world en la posicion (x, y)
     * de shape y material asignado.
     * Al liberarse el block tambien se libera shape y material. */
    Block(World *world,
          float x, float y,
          Shape *shape, Material *material);

    /* Libera los recursos utilizados */
    ~Block();

    /* Devuelve una update del bloque */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con body */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Destruye a la bala */
    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact) override;

    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact) override;
    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);
};

#endif
