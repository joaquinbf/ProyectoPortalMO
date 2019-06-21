#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__

#include <cstdint>
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"

class World;
class Action;

class GameLoop {
private:
    World *world;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 50;
    const uint32_t POSITION_ITERATIONS = 50;

public:
    /* Instancia un constrolador de game loop para world */
    GameLoop(World *world);

    /* Ejecuta input externo */
    void executeExternalInput(ProtectedQueue<Action> *inputs);

    /* Genera una simulacion */
    void step();

    /* Rellena con uodates a ext_updates */
    void fillUpdates(ProtectedQueue<Update> *ext_updates);
};

#endif
