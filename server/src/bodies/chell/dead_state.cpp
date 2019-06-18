#include "../../../include/bodies/chell/dead_state.h"

#include "../../../include/world.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../include/instructions/destroy_body_instruction.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"

DeadState::DeadState(Chell *chell):
    ChellState(chell, STATUS::CHELL_DIE),
    step_count(0) {
}

void DeadState::handleBeginContactWith(Bullet *bullet) {
}

void DeadState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        World *world = this->chell->getWorld();
        Update update = this->chell->createUpdate(COMMAND::DESTROY_COMMAND);
        world->addUpdate(update);
        world->removeFromChells(this->chell);
        world->destroyBody(this->chell);
    }
}
