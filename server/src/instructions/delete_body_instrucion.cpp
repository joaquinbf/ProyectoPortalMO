#include "../../include/instructions/delete_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"

DeleteBodyInstruction::DeleteBodyInstruction(Body *body):
    body(body) {
}

void DeleteBodyInstruction::execute() {
    World *world = this->body->getWorld();
    world->deleteBody(body);
}
