#ifndef __GATE_TEST_H__
#define __GATE_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/gate/gate.h"
#include "../../server/include/bodies/chell/chell.h"
#include "../../server/include/bodies/receiver/receiver.h"
#include "../../server/include/bodies/launcher/launcher.h"
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/world.h"
#include "../../server/include/boolean_suppliers/boolean_block_factory.h"
#include "../../server/include/boolean_suppliers/boolean_block.h"
#include "../../common/include/types.h"

#define UNUSED_VAR(VAR) (VAR++)

class GateTest: public CxxTest::TestSuite {
public:
    void testSeCreaGateYNoLeakeaMemoria() {
        // test para correr con valgrind
        World world;
        Gate *gate = world.createGate(0, 0);
        gate++;
    }

    void testGateConUnSoloBotonCambiaEstadoAOPENINGCuandoSeActivaSuBoton() {
        World world;
        Gate *gate = world.createGate(0, 0);
        Button *button = world.createButton(1, 1);
        button->setGate(gate);
        BooleanBlockFactory* bbf = world.getBooleanBlockFactory();
        BooleanBlock *boolean_block = bbf->createSameBlock();
        boolean_block->add(button);
        gate->setBooleanSupplier(boolean_block);

        // Dejo a chell sobre el boton para que sea presionado.
        Chell *chell = world.createChell(1, 1);
        UNUSED_VAR(chell);
        world.step();
        Update update = gate->createUpdate(COMMAND::UPDATE_COMMAND);

        TS_ASSERT_EQUALS(STATUS::GATE_OPENING, update.getStatus());
    }

    void testCuandoReceptorEsChocadoPorUnaBalaSeActivaEntoncesSeEmpiezaAAbrirLaCompuerta() {
        World world;
    }
};

#endif
