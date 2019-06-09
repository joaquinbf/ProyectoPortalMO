#ifndef __RECEIVER_TEST_H__
#define __RECEIVER_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/receiver/receiver.h"
#include "../../server/include/world.h"

class ReceiverTest: public CxxTest::TestSuite {
public:
    void testReceiverRecienConstruidoNoEstaActivo() {
        World world;

        Receiver *receiver = world.createReceiver(1, 1);

        TS_ASSERT(!receiver->isOn());
    }

    void testBulletChocaConReceiverYDebeActivarlo() {
        World world;
        Receiver *receiver = world.createReceiver(1, 1);
        world.createBullet(1, 1, DIRECTION::RIGHT_DIRECTION);

        world.step();

        TS_ASSERT_EQUALS(true, receiver->isOn());
    }
};

#endif
