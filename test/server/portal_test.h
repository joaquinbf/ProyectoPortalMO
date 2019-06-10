#ifndef __PORTAL_TEST_H__
#define __PORTAL_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"
#include "../../server/include/bodies/portal/portal.h"
#include "../../server/include/bodies/chell/chell.h"

class PortalTest: public CxxTest::TestSuite {
public:
    // void testCuandoChellDispararUnPortalEntoncesAumentaLaCantidadDeBodiesEnWorld() {
    //     World world;
    //     Chell *chell = world.createChell(0, 0);
    //
    //     chell->firePortalOne(10, 10);
    //
    //     TS_ASSERT_EQUALS(2, world.getBodySize());
    // }

    void testCuandoSeCreaUnPortaAumentaLaCantidadDeBodiesEnWorld() {
        World world;

        world.createPortal(b2Vec2(0, 0), b2Vec2(1, 0), 1);

        TS_ASSERT_EQUALS(1, world.getBodySize());
    }

    // void testCuandoUnPortalChocaConUnBloqueDeMetalEntoncesGuardaUnVectorUnitarioConDireccionYSentidoDeLaNormal() {
    //     World world;
    //     Block *block = world.createSquareMetalBlock(0, 0);
    //     Chell *chell = world.createChell(4, 0);
    //     chell->firePortalOne(0, 0);
    //
    //     Portal *portal = chell->getPortalOne();
    //     b2Vec2 n = portal->getN();
    //
    //     TS_ASSERT_EQUALS(n.x, 1);
    //     TS_ASSERT_EQUALS(n.y, 0);
    // }
};

#endif
