#include "../include/stage.h"
#include "../include/block.h"

Stage::Stage():
    GRAVITY(0.0, 9.8),
    b2world(this->GRAVITY),
    keep_running(true) {
}

void Stage::run() {
    this->keep_running = true;
    while (this->keep_running) {
        this->b2world.Step(
            this->TIME_STEP,
            this->VELOCITY_ITERATIONS,
            this->POSITION_ITERATIONS);
    }
}

void Stage::stop() {
    this->keep_running = false;
}

void Stage::createStageOne() {
    Block block(&this->b2world, 0, 20);
}
