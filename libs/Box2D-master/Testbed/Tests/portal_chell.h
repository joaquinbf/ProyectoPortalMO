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
        for (int i = 0; i < 7; i++) {
            this->world.createSquareMetalBlock(200 * i, -300);
        }
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
            this->chell->pressLeft();
            break;
        case GLFW_KEY_D:
            this->chell->pressRight();
            break;
        case GLFW_KEY_W:
            break;
        }
    }

    void KeyboardUp(int key) {
        switch (key) {
        case GLFW_KEY_A:
            this->chell->releaseLeft();
            break;
        case GLFW_KEY_D:
            this->chell->releaseRight();
            break;
        case GLFW_KEY_W:
            break;
        }
    }
};

#endif
