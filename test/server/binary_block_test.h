#ifndef __BINARY_BLOCK_TEST_H__
#define __BINARY_BLOCK_TEST_H__

#include "../../server/include/boolean_suppliers/simple_boolean.h"
#include "../../server/include/boolean_suppliers/binary_block.h"
#include "../../server/include/boolean_suppliers/and_operator.h"
#include "../../server/include/boolean_suppliers/or_operator.h"
#include <cxxtest/TestSuite.h>

class BinaryBlockTest: public CxxTest::TestSuite {
public:
    void testBinaryBlockAplicaANDSobreSusElementosYDevuelveTrue() {
        SimpleBoolean sb1(true);
        SimpleBoolean sb2(true);
        SimpleBoolean sb3(true);
        AndOperator and_operator;
        BinaryBlock bb(&and_operator);
        bb.pushBack(&sb1);
        bb.pushBack(&sb2);
        bb.pushBack(&sb3);

        bool r = bb.getAsBoolean();

        TS_ASSERT(r);
    }

    void testBinaryBlockAplicaORSobreTresFalsesYDaFalse() {
        SimpleBoolean sb1(false);
        SimpleBoolean sb2(false);
        SimpleBoolean sb3(false);
        OrOperator or_operator;
        BinaryBlock bb(&or_operator);
        bb.pushBack(&sb1);
        bb.pushBack(&sb2);
        bb.pushBack(&sb3);

        bool r = bb.getAsBoolean();

        TS_ASSERT_EQUALS(false, r);
    }
};

#endif
