#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <string>
#include "yaml-cpp/yaml.h"
#include "../../common/include/types.h"
#include <cstdint>

class World;

class Serializer {
public:
    /* Carga el contenido de world desde filepath */
    void deserialize(World *world, std::string filepath) const;

private:
    void deserializeBody(World *world, ENTITY entity, int x, int y) const;
};

#endif
