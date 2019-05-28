#ifndef __PORTAL_CHELL_H__
#define __PORTAL_CHELL_H__

#include "../../../../server/include/world.h"

class PortalChell: public Test {
private:
    World world;

public:
    PortalChell() {
        // setters
        this->world.setB2World(this->m_world);
        this->world.setGravity(0.0, -20);
        this->world.addChell(0, 0);
        this->world.addGround(-100, -10, 100, -10);
    }

    void Step(Settings *settings) {
        Test::Step(settings);
    }

    static Test *Create() {
        return new PortalChell;
    }

    void Keyboard(int key) {
        Chell *chell = this->world.getChell();
		switch (key) {
		case GLFW_KEY_A:
            chell->left();
			break;
        case GLFW_KEY_D:
            chell->right();
            break;
        case GLFW_KEY_W:
            chell->up();
            break;
		}
	}

    void KeyboardUp(int key) {
        Chell *chell = this->world.getChell();
		switch (key) {
        case GLFW_KEY_A:
            chell->stopLeft();
			break;
        case GLFW_KEY_D:
            chell->stopRight();
            break;
        case GLFW_KEY_W:
            break;
		}
	}
};

#endif