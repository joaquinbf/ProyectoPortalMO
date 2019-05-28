#ifndef __WORLD_H__
#define __WORLD_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"

#include "chell/chell.h"
#include "block/block.h"
#include "block/material.h"
#include "block/stone_material.h"
#include "block/shape.h"
#include "block/square_shape.h"

#include "../../common/include/socket.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/thread.h"

#include "command.h"
#include "player.h"

#include <vector>
#include <map>

class World {
private:
    b2World *b2world;
    std::vector<Chell *> chells;
    std::vector<Block *> blocks;
    std::vector<Player *> players;
    ProtectedQueue<Command *> commands;
    ProtectedQueue<Update> updates;
    bool keep_running;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;

public:
    ~World();
    void executeInputs();
    void step();

    void setB2World(b2World *b2World);

    /* Setea la gravedad mediante el vector (x, y) */
    void setGravity(float x, float y);

    /* Agrega Chell en las posiciones (x, y) de world. */
    void addChell(float x, float y);

    /* Agrega un suelo entre las posiciones (x1, y1) a (x2, y2) */
    void addGround(float x1, float y1, float x2, float y2);

    /* Devuelve un puntero a la unica chell (por mientras) de world */
    Chell *getChell();

    /* Agrega un bloque cuadrado de piedra en (x, y) */
    void addSquareStoneBlock(float x, float y);

    /* Agrega un jugador */
    void addPlayer(Socket socket);
};

#endif
