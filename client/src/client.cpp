#include "../../common/include/person.h"
#include <iostream>

int main() {
    Person p(25);
    std::cout << "AGE: " << p.getAge() << std::endl;
    std::cout << "MAX AGE: " << p.getMaxAge() << std::endl;    
    return 0;
}
