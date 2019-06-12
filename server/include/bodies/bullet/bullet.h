#ifndef __BULLET_H__
#define __BULLET_H__

#include "../body.h"
#include "../../../include/world.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

class Block;
class Launcher;
class Receiver;
class Portal;

class Bullet: public Body {
private:
    DIRECTION direction;
    const float WIDTH = 1.00;
    const float HEIGHT = 0.60;
    const float SPEED = 10;
    b2Vec2 velocity;

public:
    /* Instancia una bala en world en la posicion (x, y) moviendose con
     * direccion 'direction' */
    Bullet(World *world, float x, float y, DIRECTION direction);

    ~Bullet();

   /* Crea una update con el comando indicado */
   virtual Update createUpdate(COMMAND command) const;

   /* Maneja el inicio de contacto con otro cuerpo */
   virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

   /* Muere al chocar con un bloque */
   virtual void handleBeginContactWith(Block *block, b2Contact *contact) override;

   /* Muere al chocar con un lanzador */
   virtual void handleBeginContactWith(Launcher *launcher, b2Contact *contact) override;

   /* Transportaa bullet al otro portal si esta activo */
    virtual void handleBeginContactWith(Portal *receiver, b2Contact *contact) override;

   /* Muere y activa el receptor */
   virtual void handleBeginContactWith(Receiver *receiver, b2Contact *contact) override;

   /* Maneja el fin de contacto con otro cuerpo */
   virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

   /* Mantiene a la bala en su direccion */
   virtual void applyStateAction() override;

private:

    /* settea la velocidad de la bala con la direccion dada por v y la
     * magnitud SPEED.
     * Pre: v debe ser un vector unitario. */
    void setVelocity(b2Vec2 v);
};

#endif
