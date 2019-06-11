#ifndef __PORTAL_CHELL_H__
#define __PORTAL_CHELL_H__

#include "../../../../server/include/world.h"
#include "../../../../server/include/bodies/chell/chell.h"
#include "../../../../server/include/bodies/block/block.h"
#include "../../../../server/include/bodies/button/button.h"
#include "../../../../server/include/bodies/gate/gate.h"
#include "../../../../server/include/bodies/receiver/receiver.h"
#include "../../../../common/include/update.h"
#include <iostream>

class PortalChell: public Test {
private:
    World world;
    Chell *chell;

    public:
    PortalChell():
        world(this->m_world) {
        this->m_world->SetGravity(b2Vec2(0.0, -9.8));

        for (int i = 0; i < 1; i++) {
            this->chell = this->world.createChell(-6.00 + 2.00*i, 1.00);
        }

        for (int i = 0; i < 3; i++) {
            this->world.createSquareMetalBlock(-6.00 + 2.00*i, -1.00);
        }
        this->world.createSquareMetalBlock(-6.00 + 2.00*-10, 1.00);
        this->world.createSquareMetalBlock(-6.00 + 2.00*10, 1.00);



    }

    void Step(Settings *settings) {
        Test::Step(settings);
        this->world.bigStep();
    }

    static Test *Create() {
        return new PortalChell();
    }

    void Keyboard(int key) {
        switch (key) {
        case GLFW_KEY_A:
            std::cout << "pressed left" << std::endl;
            this->chell->pressLeft();
            break;
        case GLFW_KEY_D:
            std::cout << "pressed right" << std::endl;
            this->chell->pressRight();
            break;
        case GLFW_KEY_W:
            std::cout << "pressed up" << std::endl;
            this->chell->pressUp();
            break;
        }
    }

    void KeyboardUp(int key) {
        switch (key) {
        case GLFW_KEY_A:
            std::cout << "released left" << std::endl;
            this->chell->releaseLeft();
            break;
        case GLFW_KEY_D:
            std::cout << "released right" << std::endl;
            this->chell->releaseRight();
            break;
        case GLFW_KEY_W:
            std::cout << "released up" << std::endl;
            this->chell->releaseUp();
            break;
        }
    }

    virtual void MouseDown(const b2Vec2& p) override {
        std::cout << "(" << p.x << ", " << p.y <<  ")" << std::endl;
        if (p.x < 0) {
            this->chell->firePortalOne(p.x, p.y);
        } else {
            this->chell->firePortalTwo(p.x, p.y);
        }
    }



};

#endif
