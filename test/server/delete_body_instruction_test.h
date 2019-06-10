#ifndef __DELETE_BODY_INSTRUCTION_TEST_H__
#define __DELETE_BODY_INSTRUCTION_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/instructions/delete_body_instruction.h"


class DeleteBodyInstructionTest: public CxxTest::TestSuite {
public:
    void testCuandoSeCreaUnaBalaYLuegoSeEliminaEntoncesLaCantidadDeBodiesDisminuye() {
        World world;

        Bullet *bullet = world.createBullet(0, 0, DIRECTION::RIGHT_DIRECTION);
        world.bigStep();
        world.addInstruction(new DeleteBodyInstruction(bullet));
        world.bigStep();

        TS_ASSERT_EQUALS(0, world.getBodySize());
    }
};

#endif
