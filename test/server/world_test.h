#ifndef __WORLD_TEST_H__
#define __WORLD_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"

class WorldTest: public CxxTest::TestSuite {
public:
    void testWorldVacioNoLeakeaMemoria() {
        World world;
    }

    void testWorldConUnaChellNoLeakeaMemoria() {
        World world;
        world.createChell(0, 0);
    }

    void testWorldConCuatroChellsNoLeakea() {
        World world;

        for (int i = 0; i < 4; i++) {
            world.createChell(0, 0);
        }
    }

    void testWorldConBloquesNoLeakea() {
        World world;
        for (int i = 0; i < 20; i++) {
            world.createSquareMetalBlock(i, i);
        }
    }
};

#endif
