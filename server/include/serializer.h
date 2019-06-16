#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <string>
#include "yaml-cpp/yaml.h"
#include "../../common/include/types.h"
#include "../../server/include/boolean_suppliers/boolean_supplier.h"
#include <cstdint>

#define X_SERIAL_FACTOR 16.00
#define Y_SERIAL_FACTOR -16.00
#define Y_BUTTON -0.78
#define Y_GATE -1.00

class World;
class Gate;
class Receiver;
class Button;

struct GateLogic {
    std::map<int, Gate *> gates;
    std::map<int, BooleanSupplier *> booleansups;
};

class Serializer {
public:
    /* Carga el contenido de world desde filepath */
    void deserialize(World *world, std::string filepath) const;

private:
    void deserializeBody(
        World *world, const YAML::Node &celda,
        GateLogic &gate_logic) const;

    void connect(
        const YAML::Node &config,
        GateLogic &gate_logic) const;

    void add(Gate *gate, BooleanSupplier *booleansup, bool negate) const;
};

#endif
