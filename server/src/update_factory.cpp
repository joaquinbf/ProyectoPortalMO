#include "../include/update_factory.h"
#include "../include/bodies/body.h"
#include "../include/bodies/chell/chell.h"


Update UpdateFactory::createUpdate(Body *body) const {
    Update update;
    body->fillBodyId(update);
    body->fillPosition(update, ZOOM_FACTOR);
    body->fillDetails(update, this);
    return update;
}

void UpdateFactory::fillIdClass(Update &update, const Chell *chell) const {
    update.setIdClass(ENTITY::CHELL);
}
