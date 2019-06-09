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

class Bullet: public Body {
private:
    DIRECTION direction;
    const float WIDTH = 1.00;
    const float HEIGHT = 0.60;
    const float VELOCITY = 10;

public:
    /* Instancia una bala en world en la posicion (x, y) moviendose con
     * direccion 'direction' */
    Bullet(World *world, float x, float y, DIRECTION direction);

    ~Bullet();

   /* Crea una update con el comando indicado */
   virtual Update createUpdate(COMMAND command) const;

   /* Maneja el inicio de contacto con otro cuerpo */
   virtual void handleBeginContactWith(Body *other_body);

   /* Muere al chocar con un bloque */
   virtual void handleBeginContactWith(Block *block) override;

   /* Muere al chocar con un lanzador */
   virtual void handleBeginContactWith(Launcher *launcher) override;

   /* Muere y activa el receptor */
   virtual void handleBeginContactWith(Receiver *receiver) override;

   /* Maneja el fin de contacto con otro cuerpo */
   virtual void handleEndContactWith(Body *other_body);

   /* Mantiene a la bala en su direccion */
   virtual void applyStateAction() override;

private:

    /* settea la velocidad de la bala */
    void setVelocity();
};

#endif
