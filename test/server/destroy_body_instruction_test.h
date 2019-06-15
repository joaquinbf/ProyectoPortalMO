#ifndef __DESTROY_BODY_INSTRUCTION_TEST_H__
#define __DESTROY_BODY_INSTRUCTION_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/instructions/destroy_body_instruction.h"


class DestroyBodyInstructionTest: public CxxTest::TestSuite {
public:
    void testCuandoSeCreaUnaBalaYLuegoSeEliminaEntoncesLaCantidadDeBodiesDisminuye() {
        World world;

        Bullet *bullet = world.createBullet(0, 0, DIRECTION::RIGHT_DIRECTION);
        world.bigStep();
        world.addInstruction(new DestroyBodyInstruction(bullet));
        world.bigStep();

        TS_ASSERT_EQUALS(0, world.getBodySize());
    }
};

#endif
