#include "../../include/update_factories/update_factory.h"
#include "../../include/bodies/body.h"
#include "../../include/bodies/chell/chell.h"


Update UpdateFactory::createUpdate(COMMAND command, Body *body) const {
    Update update;
    update.setCommand(command);
    body->fillBodyId(update);
    body->fillPosition(update, this);
    body->fillIdClass(update, this);
    body->fillDirection(update, this);
    return update;
}

void UpdateFactory::fillPosition(Update &update, float x, float y) const {
    update.setPosX(x * ZOOM_FACTOR);
    update.setPosY(y * ZOOM_FACTOR);
}

void UpdateFactory::fillIdClass(Update &update, const Chell *chell) const {
    update.setIdClass(ENTITY::CHELL);
}

void UpdateFactory::fillIdClass(
    Update &update,
    const SquareShape *shape,
    const StoneMaterial *material) const {
    update.setIdClass(ENTITY::STONE_BLOCK);
}

void UpdateFactory::fillIdClass(
    Update &update,
    const SquareShape *shape,
    const MetalMaterial *material) const {
    update.setIdClass(ENTITY::METAL_BLOCK);
}

void UpdateFactory::fillIdClass(
    Update &update,
    const DiagonalShape *shape,
    const MetalMaterial *material) const {
    update.setIdClass(ENTITY::METAL_TRIAG_BLOCK);
}

void UpdateFactory::fillIdClass(
    Update &update,
    const DiagonalShape *shape,
    const StoneMaterial *material) const {
    update.setIdClass(ENTITY::NONE_ENTITY);
}


void UpdateFactory::fillDirection(Update &update, const Body *body) const {
    update.setDirection(0);
}

void UpdateFactory::fillDirection(Update &update, const Chell *chell) const {
    uint32_t direccion = chell->isFacingRight() ? 1 : 0;
    update.setDirection(direccion);
}
