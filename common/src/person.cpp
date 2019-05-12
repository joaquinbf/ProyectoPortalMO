#include "../include/person.h"

Person::Person(int age): age(age) {
}

int Person::getAge() const {
    return this->age;
}

int Person::getMaxAge() const {
    return MAX_AGE;
}
