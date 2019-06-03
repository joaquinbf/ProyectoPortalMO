#ifndef __NOT_BLOCK_TEST_H__
#define __NOT_BLOCK_TEST_H__

#include "../../server/include/boolean_suppliers/not_block.h"
#include "../../server/include/boolean_suppliers/simple_boolean.h"
#include <cxxtest/TestSuite.h>

class NotBlockTest: public CxxTest::TestSuite {
public:
    void testNotBlockNiegaElValorQueTieneEnSuInterior() {
        SimpleBoolean sb(true);
        NotBlock nb(&sb);
        TS_ASSERT_EQUALS(nb.getAsBoolean(), !sb.getAsBoolean());
    }
};

#endif
