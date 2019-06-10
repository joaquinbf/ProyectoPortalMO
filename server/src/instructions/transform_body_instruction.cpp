#include "../../include/instructions/transform_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"

TransformBodyInstruction::TransformBodyInstruction(Body *body):
    body(body) {
}

void TransformBodyInstruction::execute() {
    World *world = this->body->getWorld();
    world->deleteBody(body);
}
