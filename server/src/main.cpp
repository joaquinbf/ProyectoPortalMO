#include "../include/server.h"
#include <iostream>

#define ARG_MAIN_SERVER 2

int main(int argc, char *argv[]) {

    if (argc != ARG_MAIN_SERVER) {
        return 1;
    }

    Server server(argv[NPORT]);
    return server.main();
}
