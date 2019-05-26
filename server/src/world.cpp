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

}

void World::createWorldOne() {
    std::cout << "create world one" << std::endl;
    Chell *chell = new Chell(&this->b2world, 0, 20);
    this->bodies.emplace_back(chell);
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
    ProtectedQueue<Action> *queue = player->getInputReceiver()->getQueue();
    Action action;
    Chell *chell = (Chell *) this->bodies.front();

    while (queue->try_pop(action)) {
        switch (action.getAction()) {
            case ACTION::RUN_LEFT:
                std::cout << "run left" << std::endl;
                chell->walkLeft();
                break;
            case ACTION::RUN_RIGHT:
                std::cout << "run right" << std::endl;
                chell->walkRight();
                break;
            case ACTION::JUMP:
                std::cout << "jump" << std::endl;
                chell->jump();
                break;
            default:
                std::cout << "action no reconocida!" << std::endl;
                break;
        }
    }
}

void World::updateAllPlayers() {
    for (Player *player: this->players) {
        this->updatePlayer(player);
    }
}

void World::updatePlayer(Player *player) {
    b2Body *b2body = this->b2world.GetBodyList();

    for (; b2body != NULL; b2body = b2body->GetNext()) {
        std::cout << "PTR a BODY:  " << b2body << std::endl;
        b2Vec2 vel = b2body->GetLinearVelocity();
        b2Vec2 pos = b2body->GetPosition();

        if (vel.y >= 0) {
            Update update(
                0,
                STATUS::CHELL_FALLING,
                pos.x - 1 ,
                pos.y - 2,
                1);
            for (Player *player: this->players) {
                ProtectedQueue<Update> *queue = player->getUpdateSender()->getQueue();
                queue->push(update);
            }
        }
    }
    std::cout << "saliendo del for de update" << std::endl;
}

void World::freeBodies() {
    for (Body *body: this->bodies) {
        delete body;
    }
}
