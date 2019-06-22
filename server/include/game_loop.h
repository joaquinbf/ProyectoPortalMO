#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__

#include <cstdint>
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"

#include <set>
#include <deque>
#include <map>

class World;
class Action;
class Chell;
class Body;

class GameLoop {
private:
    World *world;
    std::map<uint32_t, Chell *> *chells;
    std::set<Body *> *bodies;
    std::deque<Update> *internal_updates;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 50;
    const uint32_t POSITION_ITERATIONS = 50;

public:
    /* Instancia un constrolador de game loop para world */
    GameLoop(
        World *world,
        std::set<Body *> *bodies,
        std::deque<Update> *updates);

    /* Ejecuta input externo */
    void executeExternalInput(ProtectedQueue<Action> *inputs);

    /* Genera una simulacion */
    void step();

    /* Rellena con uodates a ext_updates */
    void fillUpdates(ProtectedQueue<Update> *ext_updates);

private:
    /* Genera una simulacion de world */
    void worldStep();

    /* Aplica instrucciones dadas por los mismos bodies*/
    void applyInternalInstructions();

    /* Aplica instrucciones de estado sobre los bodies */
    void applyStateActions();

    /* Crea updates */
    void createUpdates();
};

#endif
