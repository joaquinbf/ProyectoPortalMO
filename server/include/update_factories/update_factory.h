#ifndef __UPDATE_FACTORY_H__
#define __UPDATE_FACTORY_H__

#include "../../../common/include/types.h"
#include "../../../common/include/update.h"


class Body;
class Chell;

class SquareShape;
class DiagonalShape;
class StoneMaterial;
class MetalMaterial;

class UpdateFactory {
public:
    Update createUpdate(COMMAND command, Body *body) const;
    void fillPosition(Update &update, float x, float y) const;

    void fillIdClass(Update &update, const Chell *chell) const;
    void fillIdClass(
        Update &update,
        const SquareShape *shape,
        const StoneMaterial *material) const;

    void fillIdClass(
        Update &update,
        const SquareShape *shape,
        const MetalMaterial *material) const;

    void fillIdClass(
        Update &update,
        const DiagonalShape *shape,
        const StoneMaterial *material) const;

    void fillIdClass(
        Update &update,
        const DiagonalShape *shape,
        const MetalMaterial *material) const;

    void fillDirection(Update &update, const Body *body) const;
    void fillDirection(Update &update, const Chell *chell) const;

private:
};

#endif
