#ifndef __PROTECTED_QUEUE_TEST_H__
#define __PROTECTED_QUEUE_TEST_H__

#include "../common/include/protected_queue.h"
#include <cxxtest/TestSuite.h>

class ProtectedQueueTest: public CxxTest::TestSuite {
public:
    void testNuevaColaDebeEstarVacia() {
        ProtectedQueue<int> pq;
        TS_ASSERT(pq.isEmpty());
    }
};

#endif
