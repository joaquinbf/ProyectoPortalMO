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

    void testCuandoUnaBalaTocaUnPortalApareceCercanoALaPosicionDelPortalOpuesto() {
        World world;
        Bullet *bullet = world.createBullet(0, 0, DIRECTION::RIGHT_DIRECTION);
        Portal *portal_one = world.createPortal(1);
        Portal *portal_two = world.createPortal(2);
        portal_one->setPosition(b2Vec2(1, 0));
        portal_one->setNormal(b2Vec2(-1, 0));
        portal_one->turnOn();
        portal_two->setPosition(b2Vec2(100, 0));
        portal_two->setNormal(b2Vec2(1, 0));
        portal_two->turnOn();
        portal_one->setPairWith(portal_two);
        portal_two->setPairWith(portal_one);

        // En aprox 20 steps = 1 seg deberia tocar el primer portal.
        for (int i = 0; i < 20; i++) {
            world.step();
            world.applyStateActions();
            world.deleteBodiesForDeletion();
        }

        // Deberia estar mas o menos en x > 100
        TS_ASSERT_DELTA(100, bullet->getPosX(), 10);
    }

    void testCuandoUnaBalaTocaUnPortalDebeAparecerEnElPortalOpuestoManteniendoLaMagnitudDeVelocidad() {
        // World world;
        // Portal *portal_one = world.createPortal(1);
        // Portal *portal_two = world.createPortal(2);
        // portal_one->setPairWith(portal_two);
        // portal_one->setPosition(b2Vec2(0, 3));
        // portal_one->setNormal(b2Vec2(-1, 0));
        // portal_one->turnOn();
        // portal_two->setPosition(b2Vec2(0, -4));
        // portal_two->setNormal(b2Vec2(-1, 0));
        // portal_two->turnOn();
        // Bullet *bullet = world.createBullet(0, 0, DIRECTION::RIGHT_DIRECTION);
        //
        // float v0 = bullet->getMagnitudOfVelocity();
        // for (int i = 0; i < 1000; i++) {
        //     world.step();
        //     world.applyStateActions();
        //     world.deleteBodiesForDeletion();
        // }
        //
        // float v1 = bullet->getMagnitudOfVelocity();
        // TS_ASSERT_EQUALS(v0, v1);
    }
};

#endif
