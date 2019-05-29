#include "../include/server.h"
#include <exception>
#include <iostream>

int main() {
    try {
        Server server;
        return server.main();
    } catch (const std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}
