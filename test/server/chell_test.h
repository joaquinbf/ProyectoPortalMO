#ifndef __CHELL_TEST_H__
#define __CHELL_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/chell/chell.h"
#include "../../server/include/bodies/portal/portal.h"
#include "../../server/include/bodies/block/block.h"

class ChellTest: public CxxTest::TestSuite {
public:
    void testCuandoChellDisparaUnPortalContraUnBloqueCuadradoMetalicoEntoncesDebeAparecerUnPortalCerca() {
        World world;
        Chell *chell = world.createChell(0, 0);
        world.createSquareMetalBlock(10, 0);
        world.bigStep();

        chell->firePortalOne(1, 0);
        world.bigStep();

        Portal *portal = chell->getPortalOne();
        TS_ASSERT_DELTA(10, portal->getPosX(), 2);
    }
};

#endif
