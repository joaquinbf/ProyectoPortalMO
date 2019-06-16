#include "../include/serializer.h"

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "../include/world.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"
#include "../../editor/editor_defines.h"

void Serializer::deserialize(World *world, std::string filepath) const {
    YAML::Node config = YAML::LoadFile(filepath);
    YAML::Node escenario = config["escenario"];
    std::size_t cant_celdas = escenario["cantidadCeldas"].as<std::size_t>();

    for (std::size_t i = 0; i < cant_celdas; ++i) {
        if (config["celdas"][i]["ocupado"].as<bool>()) {
            int idclass = config["celdas"][i]["idClass"].as<int>();
            int x = config["celdas"][i]["x"].as<int>();
            int y = config["celdas"][i]["y"].as<int>();
            this->deserializeBody(world, idclass, x, y);
        }
    }
}

void Serializer::deserializeBody(
    World *world, int idclass, int editor_x, int editor_y) const {
    float x = editor_x/SERIAL_FACTOR;
    float y = editor_y/SERIAL_FACTOR;

    switch (idclass) {
        case IDCLASS_NULL:
            break;
        case IDCLASS_CHELL:
            world->createChell(x, y);
            break;
        case IDCLASS_BLOQUE_ROCA:
            world->createSquareStoneBlock(x, y);
            break;
        case IDCLASS_BLOQUE_METAL:
            world->createSquareMetalBlock(x, y);
            break;
        case IDCLASS_COMPUERTA_REG:
            world->createGate(x, y);
            break;
        case IDCLASS_COMPUERTA_AND:
            world->createAndGate(x, y);
            break;
        case IDCLASS_COMPUERTA_OR:
            world->createOrGate(x, y);
            break;
        case IDCLASS_BOTON:
            world->createButton(x, y);
            break;
        case IDCLASS_RECEPTOR:
            world->createReceiver(x, y);
            break;
        case IDCLASS_PASTEL:
            world->createCake(x, y);
            break;
        case IDCLASS_ACIDO:
            world->createAcid(x, y);
            break;
        case IDCLASS_ROCA:
            world->createRock(x, y);
            break;
        // case IDCLASS_BARRERA_VERTICAL:
        // case IDCLASS_BARRERA_HORIZONTAL:
        case IDCLASS_DIAGONAL_0:
            world->createDiagonalMetalBlock(x, y, ORIENTATION::ORIENTATION_0);
            break;
        case IDCLASS_DIAGONAL_90:
            world->createDiagonalMetalBlock(x, y, ORIENTATION::ORIENTATION_3);
            break;
        case IDCLASS_DIAGONAL_180:
            world->createDiagonalMetalBlock(x, y, ORIENTATION::ORIENTATION_2);
            break;
        case IDCLASS_DIAGONAL_270:
            world->createDiagonalMetalBlock(x, y, ORIENTATION::ORIENTATION_1);
            break;
        case IDCLASS_EMISOR_0:
            world->createLauncher(x, y, DIRECTION::RIGHT_DIRECTION);
            break;
        case IDCLASS_EMISOR_90:
            world->createLauncher(x, y, DIRECTION::UP_DIRECTION);
            break;
        case IDCLASS_EMISOR_180:
            world->createLauncher(x, y, DIRECTION::LEFT_DIRECTION);
            break;
        case IDCLASS_EMISOR_270:
            world->createLauncher(x, y, DIRECTION::DOWN_DIRECTION);
    }
}
