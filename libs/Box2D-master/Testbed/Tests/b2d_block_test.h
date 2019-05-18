#ifndef __BLOCK_B2DTEST_H__
#define __BLOCK_B2DTEST_H__

#include "../../../../server/include/block.h"

class B2DBlockTest: public Test {
public:
    B2DBlockTest() {
        m_world->SetGravity(b2Vec2(0.0f, -9.8f));
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
        myBodyDef.position.Set(0, 20); //set the starting position
        myBodyDef.angle = 0; //set the starting angle

        b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);

        b2PolygonShape boxShape;
        boxShape.SetAsBox(1,1);

        b2FixtureDef boxFixtureDef;
        boxFixtureDef.shape = &boxShape;
        boxFixtureDef.density = 1;
        dynamicBody->CreateFixture(&boxFixtureDef);

        Block block(m_world, 0, 25);
    }

    static Test *Create() {
        return new B2DBlockTest;
    }

    void Step(Settings* settings) {
        Test::Step(settings);
        g_debugDraw.DrawString(5, m_textLine, "Test Block B2D");
        m_textLine += 15;
    }
};

#endif
