#include "../include/client.h"
#include "../../common/include/person.h"
#include <iostream>

int Client::main() {
    Person p(333);
    std::cout << "client age: " << p.getAge() << std::endl;
    return 0;
}
