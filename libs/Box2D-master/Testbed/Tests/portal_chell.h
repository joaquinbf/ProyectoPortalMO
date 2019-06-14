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
            this->chell = this->world.createChell(-3.00 + 2.00*i, 1.00);
        }

        for (int i = 0; i < 3; i++) {
            this->world.createSquareMetalBlock(-6.00 + 2.00*i, -1.00);
        }

        this->world.createSquareMetalBlock(-6.00 + 2.00*10, 5.00);
        this->world.createLauncher(-10, -1, DIRECTION::LEFT_DIRECTION);
        this->world.createSquareMetalBlock(-6.00 + 2.00*-10, -1.00);

        this->world.createPortal(1, b2Vec2(10, 10), b2Vec2(1, 0));
        this->world.createPortal(1, b2Vec2(14, 14), b2Vec2(0, 1));
        this->world.createPortal(1, b2Vec2(18, 18), b2Vec2(-1, 0));
        this->world.createPortal(1, b2Vec2(22, 22), b2Vec2(0, -1));
        this->world.createPortal(1, b2Vec2(26, 26), b2Vec2(-1, 1));
        this->world.createPortal(1, b2Vec2(30, 30), b2Vec2(1, 1));
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
        PortalGun *portal_gun = this->chell->getPortalGun();
        if (p.x < 0) {
            portal_gun->firePortalOne(p.x, p.y);
        } else {
            portal_gun->firePortalTwo(p.x, p.y);
        }
    }
};

#endif
