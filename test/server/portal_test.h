#ifndef __PORTAL_TEST_H__
#define __PORTAL_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"
#include "../../server/include/bodies/portal/portal.h"
#include "../../server/include/bodies/chell/chell.h"

class PortalTest: public CxxTest::TestSuite {
public:
    void testPortalPorDefectoVieneDesactivado() {
        World world;
        Portal *portal = world.createPortal(1);

        TS_ASSERT(!portal->isOn());
    }

    void testCuandoSeCreaUnPortalLaCantidadDeBodiesEnWorldDebeAumentarEnUno() {
        World world;
        world.createPortal(1);

        TS_ASSERT_EQUALS(1, world.getBodySize());
    }

    void testSePuedeDesactivarUnPortal() {
        World world;
        Portal *portal = world.createPortal(1);

        portal->turnOn();
        portal->turnOff();

        TS_ASSERT(!portal->isOn());
    }
};

#endif
