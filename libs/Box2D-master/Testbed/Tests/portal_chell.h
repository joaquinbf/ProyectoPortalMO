#ifndef __PORTAL_CHELL_H__
#define __PORTAL_CHELL_H__

#include "../../../../server/include/world.h"
#include "../../../../server/include/bodies/chell.h"


class PortalChell: public Test {
private:
    World world;
    Chell *chell;

public:
    PortalChell():
        world(this->m_world) {
        this->chell = this->world.createChell(0, 0);
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
