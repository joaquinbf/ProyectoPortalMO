#ifndef __BULLET_TEST_H__
#define __BULLET_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/world.h"

class BulletTest: public CxxTest::TestSuite {
public:
    void testNoLeakeaMemoria() {
        // Para valgrind.
        World world;
        world.createBullet(2, 2, DIRECTION::RIGHT_DIRECTION);
    }

    void testSeDisparaUnaBalaChocaConUnBloqueYDebeDestruirse() {
        World world;
        world.createSquareMetalBlock(1, 1);
        world.createBullet(1, 1, DIRECTION::RIGHT_DIRECTION);

        world.step();
        world.deleteBodiesForDeletion();

        TS_ASSERT_EQUALS(1, world.getBodySize());
    }
};

#endif