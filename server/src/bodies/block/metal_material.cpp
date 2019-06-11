#include "../../../include/bodies/block/metal_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/world.h"
#include "../../../include/instructions/transform_body_instruction.h"
#include "../../../../common/include/types.h"
#include <cmath>
#include <iostream>


ENTITY MetalMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::METAL_TRIAG_BLOCK;
}

ENTITY MetalMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::METAL_BLOCK;
}

void MetalMaterial::tryOpenPortal(Portal *portal, b2Vec2 point, b2Vec2 normal) {
    World *world = portal->getWorld();
    float angle = acos(normal.y / normal.Length());
    world->addUpdate(portal->createUpdate(COMMAND::CREATE_COMMAND));
    portal->activate();
    portal->turnOn();
    portal->putToSleep();
    portal->setNormal(normal);
    world->addInstruction(new TransformBodyInstruction(portal, point, angle));
}
