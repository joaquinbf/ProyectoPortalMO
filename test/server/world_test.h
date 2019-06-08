#ifndef __WORLD_TEST_H__
#define __WORLD_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"

class WorldTest: public CxxTest::TestSuite {
public:
    void testWorldNoLeakeaMemoria() {
        // test para correr con valgring
        World world;
    }

    void testSeAgregaUnBodyAWorldLuegoSeEliminaYDisminuyeLaCantidadDeBodyPresentes() {
        World world;
        Bullet *bullet = world.createBullet(1, 1, DIRECTION::RIGHT_DIRECTION);
        world.step();

        world.addBodyForDeletion(bullet);
        world.deleteBodiesForDeletion();

        TS_ASSERT_EQUALS(0, world.getBodySize());
    }
};

#endif
