#include "../include/world.h"
#include <iostream>

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

World::~World() {
    this->freeBodies();
}

void World::run() {
    while (this->keep_running) {
        this->addInputsFromAllPlayers();
        this->b2world.Step(
            this->TIME_STEP,
            this->VELOCITY_ITERATIONS,
            this->POSITION_ITERATIONS);
        this->updateAllPlayers();
        usleep(100000);
    }
}

void World::stop() {
    this->keep_running = false;
}

void World::addPlayer(Player *player) {
    this->players.emplace_back(player);
    Chell *chell = new Chell(&this->b2world, 0, 20);
    this->bodies.emplace_back(chell);
    this->chells[player] = chell;
}

void World::createWorldOne() {
    std::cout << "create world one" << std::endl;
    for (int i = -3; i <= 3; i = i + 2) {
        Block *block = new Block(&this->b2world, i, 30);
        this->bodies.emplace_back(block);
    }
}

void World::sendBodiesToPlayer(Player *player) {
    std::cout << "send bodies to player" << std::endl;
    player->sendBodies(this->bodies);
}

void World::addInputsFromAllPlayers() {
    for (Player *player: this->players) {
        this->addInputsFrom(player);
    }
}

void World::addInputsFrom(Player *player) {
    ProtectedQueue<Command *> *pq = player->getInputReceiver()->getQueue();
    Command *command;
    while (pq->try_pop(command)) {
        Chell *chell = this->chells[player];
        command->execute(chell);
        delete command;
    }
}

void World::updateAllPlayers() {
    for (Player *player: this->players) {
        this->updatePlayer(player);
    }
}

void World::updatePlayer(Player *player) {
    b2Body *body = this->b2world.GetBodyList();
    Chell *chell = (Chell *) body->GetUserData();

    if (body->IsActive()) {
        ProtectedQueue<Update> *queue = player->getUpdateSender()->getQueue();
        Update update;
        chell->fillUpdate(update);
        queue->push(update);
    }
}

void World::freeBodies() {
    for (Body *body: this->bodies) {
        delete body;
    }
}
