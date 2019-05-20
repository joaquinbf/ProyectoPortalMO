#include "../include/client_manager.h"

int main() {
    ClientManager cli("4545");
    cli.sendInt();
    return 0;
}
