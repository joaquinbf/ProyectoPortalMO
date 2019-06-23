#ifndef __BLOCK_TEST_H__
#define __BLOCK_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"
#include "../../server/include/bodies/block/block.h"


class BlockTest: public CxxTest::TestSuite {
public:
    void testBlockNoLeakeaMemoria() {
        World world;
        world.getWorldBuilder()->createSquareMetalBlock(99, 99);
    }
};

#endif
