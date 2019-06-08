#include "../../../include/bodies/chell/dead_state.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../../common/include/types.h"

DeadState::DeadState(Chell *chell, STATUS status):
    ChellState(chell, STATUS::CHELL_DIE) {
}
