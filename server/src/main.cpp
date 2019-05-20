#include "../include/clientManager.h"
#include "../../common/include/socket.h"
#include "../include/stage.h"

int main() {
	Stage stage;
	stage.createStageOne();

	stage.start();
	stage.stop();
	stage.join();

    return 0;
}
