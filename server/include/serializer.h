#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <string>
#include "yaml-cpp/yaml.h"
#include "../../common/include/types.h"
#include <cstdint>

#define X_SERIAL_FACTOR 16.00
#define Y_SERIAL_FACTOR -16.00
#define Y_BUTTON -0.78
#define Y_GATE -1.00

class World;

class Serializer {
public:
    /* Carga el contenido de world desde filepath */
    void deserialize(World *world, std::string filepath) const;

private:
    void deserializeBody(
        World *world, int idclass, int editor_x, int editor_y) const;
};

#endif
