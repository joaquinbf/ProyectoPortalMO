#include "../include/stage.h"
#include "../../common/include/creator.h"
#include "../../common/include/protocol.h"
#include "../../common/include/socket.h"



Stage::Stage():
    GRAVITY(0.0, 9.8),
    b2world(this->GRAVITY),
    keep_running(true) {
}

void Stage::run() {

    Socket accepterSocket;
    accepterSocket.bindAndListen("4545");
    Protocol protocol(accepterSocket.accept());

    protocol.sendQuad(1);

    this->keep_running = true;
    while (this->keep_running) {
        this->b2world.Step(
            this->TIME_STEP,
            this->VELOCITY_ITERATIONS,
            this->POSITION_ITERATIONS);
        b2Body *bodies = this->b2world.GetBodyList();
        while (bodies != 0) {
            b2Vec2 pos = bodies->GetPosition();
            Creator creator(0, 0, pos.x, pos.y);
            protocol.sendCreator(creator);
            ++bodies;
        }
        break;

    }
}

void Stage::stop() {
    this->keep_running = false;
}

void Stage::createStageOne() {
    /* Solo crea una unica chell en el mundo */
    Chell chell(&this->b2world, 0, 20);
}
