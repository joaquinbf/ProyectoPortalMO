#ifndef __WORLD_TEST_H__
#define __WORLD_TEST_H__

#include <cxxtest/TestSuite.h>

class WorldTest: public CxxTest::TestSuite {
public:
    void testAddition() {
        TS_ASSERT_EQUALS(5, 2 + 3);
    }
};

#endif
