#include "../include/serializer.h"
#include "../include/world.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"
#include "yaml-cpp/yaml.h"
#include <iostream>

void Serializer::deserialize(World *world, std::string filepath) const {
    YAML::Node config = YAML::LoadFile(filepath);
    std::size_t cant_celdas = config["escenario"]["cantidadCeldas"].as<std::size_t>();

    for (std::size_t i = 0; i < cant_celdas; ++i) {
        if (config["celdas"][i]["ocupado"].as<bool>()) {
            int entity = config["celdas"][i]["idClass"].as<int>();
            int x = config["celdas"][i]["x"].as<int>();
            int y = config["celdas"][i]["y"].as<int>();
            this->deserializeBody(world, (ENTITY) entity, x, y);
        }
    }
}

void Serializer::deserializeBody(
    World *world, ENTITY entity, int x, int y) const {
    std::cout << "entity: " << entity
              << " --- (" << x << ", " << y << ")" << std::endl;
    float fx = x / (float)ZOOM_FACTOR;
    float fy = y / (float)ZOOM_FACTOR;
    switch (entity) {
        case ENTITY::METAL_BLOCK:
        std::cout << "entity: " << entity
                  << " --- (" << fx << ", " << fy << ")" << std::endl;
            world->createSquareMetalBlock(fx, fy);
            break;
        default:
            break;
    }
}
