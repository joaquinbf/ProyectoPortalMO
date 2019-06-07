#ifndef __GATE_H__
#define __GATE_H__

#include "../body.h"
#include "gate_state.h"
#include "closed_gate_state.h"
#include "opening_gate_state.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../boolean_suppliers/boolean_block.h"
#include <cstdint>

class Chell;
class Block;
class Button;
class Rock;
class BooleanBlock;

class Gate: public Body {
private:
    const float MAX_WIDTH = 2.00;
    const float MAX_HEIGHT = 4.00;
    float width;
    float height;
    ClosedGateState closed_gate_state;
    OpeningGateState opening_gate_state;
    GateState *state;
    BooleanBlock *boolean_block;

public:
    /* Instancia una compuerta de id 'body_id' en b2world en (x, y) */
    Gate(uint32_t body_id, b2World *b2world, float x, float y);

    virtual Update createUpdate(COMMAND command) const;

    /* Asigna un bloque booleano a la compuerta */
    void setBooleanBlock(BooleanBlock *boolean_block);

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body);

    /* Aplica una accion dependiendo de su estado */
    virtual void applyStateAction() override;

    /* Intenta cambiar su estado si las condiciones de boolean block
     * fueron satisfechas */
    void tryChangeState();

    /* Indica si se satisface la condicion de sus elementos */
    bool conditionIsMeet();

    /* Cambia su estado a abriendo */
    void changeStateToOpening();

    /* Achica la compuerta */
    void shrink();
};

#endif
