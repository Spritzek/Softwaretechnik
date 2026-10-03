
#include "person.h"

void Person::setName(string name) {
    _name = name;
}

string Person::name() {
    return _name;
}

void Person::setSurname(string surname) {
    _surname = surname;
}

string Person::surname() {
    return _surname;
}

int Person::setDob(unsigned int day, MONTH month, int year) {
    return 1;
    return 0;
}

Date Person::dob() {
    return _dob;
}
