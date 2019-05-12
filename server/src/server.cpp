#include "../include/server.h"
#include "../../common/include/person.h"
#include <iostream>

int Server::main() {
    Person p(99);
    std::cout << "server age: " << p.getAge() << std::endl;
    return 0;
}
