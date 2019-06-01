#ifndef __CHELL_H__
#define __CHELL_H__

#include "../body.h"
#include "chell_state.h"
#include "idle_state.h"
#include "running_state.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

class Chell: public Body {
private:
    bool is_facing_right;
    IdleState idle_state;
    RunningState running_state;
    ChellState *state;
    const float HALF_WIDTH = 100;
    const float HALF_HEIGHT = 150;
    const float DENSITY = 1;
    const float ANGLE = 0;

public:
    /* Instancia a chell de id 'body_id' sobre b2world en la
     * posicion (x, y) mirando a la derecha en estado idle. */
    Chell(uint32_t body_id, b2World *b2world, float x, float y);

    /* Hace mirar a la derecha */
    void faceRight();

    /* Hace mirar a la izquierda */
    void faceLeft();

    /* Hace mirar en la direccion opuesta */
    void faceOppositeDirection();

    /* Devuelve un update de Command de chell */
    virtual Update createUpdate(COMMAND command) const override;

    /* Presiona la tecla izquierda de chell*/
    void pressLeft();

    /* Suelta la tecla izquierda de chell. */
    void releaseLeft();

    /* Cambia el estado a running */
    void changeStateToRunning();

    /* Cambia el estado a idle */
    void changeStateToIdle();

    /* Aplica un impulso a la izquierda */
    void applyLinearImpulseToLeft();

    /* Aplica un impulso a la derecha */
    void applyLinearImpulseToRight();
};

#endif
