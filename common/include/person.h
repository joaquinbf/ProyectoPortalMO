#ifndef __PERSON_H__
#define __PERSON_H__

#define MAX_AGE 22

class Person {
private:
    int age;
public:
    Person(int age);
    int getAge() const;
    int getMaxAge() const;
};

#endif
