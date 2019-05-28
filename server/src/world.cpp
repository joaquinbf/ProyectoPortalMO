#include "../include/world.h"
#include <iostream>

World::~World() {
    // TODO: eliminar y pasar a eliminar players.
    for (Chell *chell: this->chells) {
        delete chell;
    }
}

void World::executeInputs() {
    Command *command;
    while (this->commands.try_pop(command)) {
        command->execute(this);
        delete command;
    }
}

void World::step() {
    this->executeInputs();
    this->b2world->Step(
        this->TIME_STEP,
        this->VELOCITY_ITERATIONS,
        this->POSITION_ITERATIONS);
}

void World::setB2World(b2World *b2world) {
    this->b2world = b2world;
}

void World::setGravity(float x, float y) {
    this->b2world->SetGravity(b2Vec2(x, y));
}

Chell *World::addChell(float x, float y) {
    Chell *chell = new Chell(this->b2world, x, y);
    this->chells.emplace_back(chell);
    return chell;
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
    Player *player = new Player(std::move(socket), &this->commands);
    this->players.emplace_back(player);
    player->start();
}

void World::addPlayer(Player *player) {
    Chell *chell = this->addChell(0, 0);
    player->setChell(chell);
}
