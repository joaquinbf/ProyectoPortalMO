#include "../../include/instructions/delete_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"
#include "../../common/include/update.h"

DeleteBodyInstruction::DeleteBodyInstruction(Body *body):
    body(body) {
}

// TODO: Cambiar nombre a destroy body instruction.
void DeleteBodyInstruction::execute() {
    World *world = body->getWorld();
    world->destroyBody(body);
}
