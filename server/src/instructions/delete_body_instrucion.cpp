#include "../../include/instructions/delete_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"
#include "../../common/include/update.h"

DeleteBodyInstruction::DeleteBodyInstruction(Body *body):
    body(body) {
}

void DeleteBodyInstruction::execute() {
    Update update = body->createUpdate(COMMAND::DESTROY_COMMAND);
    World *world = this->body->getWorld();
    world->addUpdate(update);
    world->deleteBody(body);
}
