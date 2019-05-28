#include "../include/world.h"

World::~World() {
    // TODO: eliminar y pasar a eliminar players.
    for (Chell *chell: this->chells) {
        delete chell;
    }
}

void World::run() {
    this->keep_running = true;
    while (this->keep_running) {
        this->executeInputs();
        this->b2world->Step(
            this->TIME_STEP,
            this->VELOCITY_ITERATIONS,
            this->POSITION_ITERATIONS);
        usleep(100000);
    }
}

void World::stop() {
    this->keep_running = false;
}

void World::executeInputs() {
    Command *command;
    while (this->commands.try_pop(command)) {
        command->execute();
        delete command;
    }
}

void World::setB2World(b2World *b2world) {
    this->b2world = b2world;
}

void World::setGravity(float x, float y) {
    this->b2world->SetGravity(b2Vec2(x, y));
}

void World::addChell(float x, float y) {
    Chell *chell = new Chell(this->b2world, x, y);
    this->chells.emplace_back(chell);
}

void World::addGround(float x1, float y1, float x2, float y2) {
    b2BodyDef bd;
    b2Body* ground = this->b2world->CreateBody(&bd);

    b2EdgeShape shape;
    shape.Set(b2Vec2(x1, y1), b2Vec2(x2, y2));
    ground->CreateFixture(&shape, 0.0f);
}

Chell *World::getChell() {
    return this->chells.front();
}

void World::addSquareStoneBlock(float x, float y) {
    Block block(this->b2world, x, y, new SquareShape(), new StoneMaterial());
}

void World::addPlayer(Socket socket) {
    Chell *chell = new Chell(this->b2world, 0, 0);
    Player *player = new Player(std::move(socket), chell, &this->commands);
    player.start();
    this->players.emplace_back(player);
}
