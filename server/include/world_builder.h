#ifndef __WORLD_BUILDER_H__
#define __WORLD_BUILDER_H__

#include <set>
#include <cstdint>

class World;
class Body;

class WorldBuilder {
private:
    World *world;
    uint32_t body_id_count;
    std::set<Body *> all_bodies;

public:
    /* Instancia un constructor de world*/
    WorldBuilder(World *world);

    /* Instancia un bloque cuadrado de metal en (x, y) */
    void createSquareMetalBlock(float x, float y);

    /* Destruye todos los cuerpos */
    void destroyAllBodies();
};

#endif
