#include "../include/server.h"
#include <iostream>

#define ARG_MAIN_SERVER 2

int main(int argc, char *argv[]) {

    if (argc != ARG_MAIN_SERVER) {
        std::cout << "Error: Argumentos insuficientes."
				  << "Modo de uso: ./portal-server <PORT>"
				  << std::endl;
        return 1;
    }

    Server server(argv[NPORT]);
    return server.main();
}
