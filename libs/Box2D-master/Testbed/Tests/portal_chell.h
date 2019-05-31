#ifndef __PORTAL_CHELL_H__
#define __PORTAL_CHELL_H__

#include "../../../../server/include/world.h"
#include "../../../../server/include/bodies/chell/chell.h"
#include "../../../../server/include/bodies/block/block.h"


class PortalChell: public Test {
private:
    World world;
    Chell *chell;

public:
    PortalChell():
        world(this->m_world) {
        this->chell = this->world.createChell(0, 0);
        this->world.createSquareMetalBlock(-6, -2);
        this->world.createSquareMetalBlock(-4, -2);
        this->world.createSquareMetalBlock(-2, -2);
        this->world.createSquareStoneBlock(0, -2);
        this->world.createSquareMetalBlock(2, -2);
        this->world.createSquareMetalBlock(4, -2);
        this->world.createSquareMetalBlock(6, -2);
    }

    void Step(Settings *settings) {
        Test::Step(settings);
    }

    static Test *Create() {
        return new PortalChell();
    }

    void Keyboard(int key) {
        switch (key) {
        case GLFW_KEY_A:
            break;
        case GLFW_KEY_D:
            break;
        case GLFW_KEY_W:
            break;
        }
    }

    void KeyboardUp(int key) {
        switch (key) {
        case GLFW_KEY_A:
            break;
        case GLFW_KEY_D:
            break;
        case GLFW_KEY_W:
            break;
        }
    }
};

#endif
