#ifndef __B2D_CHARACTER_TEST_H__
#define __B2D_CHARACTER_TEST_H__

#include "../../../../server/include/character.h"

class B2DCharacterTest: public Test {
private:
    Character c;
    bool m_button = false;
public:
    B2DCharacterTest(): c(m_world, 0, 20) {
        m_world->SetGravity(b2Vec2(0.0f, -9.8f));

        b2BodyDef bd;
        b2Body* ground = m_world->CreateBody(&bd);

        b2EdgeShape shape;
        shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));
        ground->CreateFixture(&shape, 0.0f);
    }

    static Test *Create() {
        return new B2DCharacterTest;
    }

    void Step(Settings* settings) {
        Test::Step(settings);
        g_debugDraw.DrawString(5, m_textLine, "Test Block B2D");
        m_textLine += 15;

        if (m_button) {
            c.walkLeft();
        }
    }

    void Keyboard(int key) {
        switch (key) {
            case GLFW_KEY_A:
                m_button = true;
                break;
        }
    }

    void KeyboardUp(int key)
	{
		switch (key) {
		case GLFW_KEY_A:
			m_button = false;
			break;
		}
	}
};

#endif
