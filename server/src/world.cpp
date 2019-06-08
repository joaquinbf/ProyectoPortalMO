#include "../include/world.h"

#include "../include/bodies/body.h"
#include "../include/bodies/chell/chell.h"
#include "../include/bodies/button/button.h"
#include "../include/bodies/gate/gate.h"
#include "../include/bodies/acid/acid.h"
#include "../include/bodies/bullet/bullet.h"
#include "../include/bodies/launcher/launcher.h"
#include "../include/instructions/instruction.h"
#include "../include/instructions/instruction_factory.h"
#include "../include/boolean_suppliers/boolean_block_factory.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include <cstdint>
#include <vector>
#include <list>
#include <iostream>

World::World():
    b2world(new b2World(GRAVITY)),
    body_count(0),
    b2world_is_internal(true) {
    this->b2world->SetContactListener(&this->contact_listener);
}

World::World(float time_step):
    b2world(new b2World(GRAVITY)),
    body_count(0),
    b2world_is_internal(true),
    TIME_STEP(time_step) {
}

World::World(b2World *b2world):
    b2world(b2world),
    body_count(0),
    b2world_is_internal(false) {
    this->b2world->SetContactListener(&this->contact_listener);
}

World::~World() {
    this->deleteBodies();
    this->deleteB2WorldIfInternal();
}

uint32_t World::getBodyCount() const {
    return this->body_count;
}

uint32_t World::getBodySize() const {
    return this->bodies.size();
}

b2World *World::getB2World() {
    return this->b2world;
}

Chell *World::createChell(float x, float y) {
    Chell *chell = new Chell(this->getBodyCount(), this, x, y);
    this->bodies.push_back(chell);
    this->chells[chell->getBodyId()] = chell;
    this->body_count++;
    return chell;
}

Block *World::createSquareMetalBlock(float x, float y) {
    Shape *shape = new SquareShape();
    Material *material = new MetalMaterial();
    Block *block = new Block(this->getBodyCount(), this,
                             x, y,
                             shape, material);
    this->bodies.push_back(block);
    this->body_count++;
    return block;
}

Block *World::createSquareStoneBlock(float x, float y) {
    Shape *shape = new SquareShape();
    Material *material = new StoneMaterial();
    Block *block = new Block(this->getBodyCount(), this,
                             x, y,
                             shape, material);
    this->bodies.push_back(block);
    this->body_count++;
    return block;
}

Button *World::createButton(float x, float y) {
    Button *button = new Button(this->getBodyCount(), this, x, y);
    this->bodies.push_back(button);
    return button;
    this->body_count++;
}

void World::createGateWithButton(
    float x1, float y1,
    float x2, float y2,
    bool open_gate_when_button_is_pressed) {
    Gate *gate = new Gate(this->getBodyCount(), this, x1, y1);
    this->bodies.push_back(gate);
    this->body_count++;

    Button *button = new Button(this->getBodyCount(), this, x2, y2);
    this->body_count++;
    this->bodies.push_back(button);

    button->setGate(gate);

    BooleanBlock *block;
    if (open_gate_when_button_is_pressed) {
        block = this->boolean_block_factory.createSameBlock();
    } else {
        block = this->boolean_block_factory.createNotBlock();
    }

    block->add(button);
    gate->setBooleanBlock(block);
}

Gate *World::createGate(float x, float y) {
    Gate *gate = new Gate(this->getBodyCount(), this, x, y);
    this->bodies.push_back(gate);
    this->body_count++;
    return gate;
}

Acid *World::createAcid(float x, float y) {
    Acid *acid = new Acid(this->getBodyCount(), this, x, y);
    this->bodies.push_back(acid);
    this->body_count++;
    return acid;
}

Launcher *World::createLauncher(float x, float y, DIRECTION direction) {
    Launcher *launcher = new Launcher(
        this->getBodyCount(), this,
        x, y,
        direction);
    this->bodies.push_back(launcher);
    this->body_count++;
    return launcher;
}

Bullet *World::createBullet(float x, float y, DIRECTION direction) {
    Bullet *bullet = new Bullet(this->body_count, this, x, y, direction);
    this->bodies.push_back(bullet);
    this->body_count++;
    return bullet;
}


std::list<Update> World::getNewPlayerUpdates() const {
    return this->getUpdatesWithCommand(COMMAND::CREATE_COMMAND);
}

std::list<Update> World::getUpdates() const {
    return this->getUpdatesWithCommand(COMMAND::UPDATE_COMMAND);
}

void World::createNewPin(uint32_t id, int32_t x, int32_t y){
    Pin* ptr = new Pin(this->body_count,x,y);
    this->body_count++;
    if(this->pins.find(id) != this->pins.end()){
        //std::cout<<"CHUCHA\n";
        //ya hay un pin (chucha)
    } else {
        this->pins[id] = ptr;
    }
}

std::list<Update> World::getPinUpdateList(){
    std::list<Update> list;
    Update update;
    for( auto it : this->pins){
        if(it.second != nullptr){
            if(it.second->hasUpdate()){
                update = it.second->getUpdate();
                if(update.getCommand()!=COMMAND::DESTROY_COMMAND){
                    delete it.second;
                    this->pins.erase(it.first);
                }
                list.push_back(update);
            }
        }
    }
    return list;
}

std::list<Update> World::getUpdatesForAwakeBodies() const {
    std::list<Update> updates;

    for (Body *body: this->bodies) {
        if (body->isAwake()) {
            Update update = body->createUpdate(COMMAND::UPDATE_COMMAND);
            updates.push_back(update);

            if (update.getIdClass() == ENTITY::CHELL && false) {
                std::cout << "POS : ("
                          << update.getPosX() << ", "
                          << update.getPosY() << ")" << std::endl;

                switch (update.getStatus()) {
                case STATUS::NONE_STATUS:
                    std::cout << "UPDATE STATUS: NONE_STATUS" << std::endl;
                    break;
                case STATUS::CHELL_IDLE:
                    std::cout << "UPDATE STATUS: CHELL_IDLE" << std::endl;
                    break;
                case STATUS::CHELL_RUNNING:
                    std::cout << "UPDATE STATUS: CHELL_RUNNING" << std::endl;
                    break;
                case STATUS::CHELL_JUMPING:
                    std::cout << "UPDATE STATUS: CHELL_JUMPING" << std::endl;
                    break;
                case STATUS::CHELL_DIE:
                    std::cout << "UPDATE STATUS: CHELL_DIE" << std::endl;
                    break;
                default:
                    std::cout << "UPDATE STATUS: OTRO STATUS : "
                              << update.getStatus() << std::endl;
                    break;
                }
            } else if (update.getStatus() == STATUS::GATE_CLOSED) {
                std::cout << "STATUS::GATE_CLOSED" << std::endl;
            } else if (update.getStatus() == STATUS::GATE_OPENING) {
                std::cout << "STATUS::GATE_OPENING" << std::endl;
            } else if (update.getStatus() == STATUS::GATE_OPENED) {
                std::cout << "STATUS::GATE_OPENED" << std::endl;
            } else if (update.getStatus() == STATUS::GATE_CLOSING) {
                std::cout << "STATUS::GATE_CLOSING" << std::endl;
            }
        }
    }
    return updates;
}


void World::step() {
    this->b2world->Step(this->TIME_STEP,
                        this->VELOCITY_ITERATIONS,
                        this->POSITION_ITERATIONS);
}

void World::createWorldOne() {
    for (int i = 0; i < 4; i++) {
        this->createChell(-6.00 + 2.00*i, 1.00);
    }

    for (int i = -10; i < 10; i++) {
        this->createSquareMetalBlock(-6.00 + 2.00*i, -1.00);
    }

    this->createGateWithButton(6.00, 2.00, 1.00, Cy, true);
    this->createAcid(0, 5);
}

void World::applyAction(const Action &action) {
    InstructionFactory insf;
    Instruction *instruction = insf.createInstruction(action,this->chells,this);
    instruction->execute();
    delete instruction;
}

void World::applyStateActions() {
    for (Body *body: this->bodies) {
        body->applyStateAction();
    }
}

BooleanBlockFactory *World::getBooleanBlockFactory() {
    return &this->boolean_block_factory;
}

void World::deleteBodies() {
    for (Body *body: this->bodies) {
        delete body;
    }
}

void World::deleteB2WorldIfInternal() {
    if (this->b2world_is_internal) {
        delete this->b2world;
    }
}

std::list<Update> World::getUpdatesWithCommand(COMMAND command) const {
    std::list<Update> lista;

    for (Body *body: this->bodies) {
        Update update = body->createUpdate(command);
        lista.emplace_back(update);
        std::cout << "UPDATE: (" << update.getPosX()
                  << " ," << update.getPosY() << ")" << std::endl;
    }

    return lista;
}
