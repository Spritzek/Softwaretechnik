
#include "person.h"

void person::setName(string name) {
    _name = name;
}

string person::name() {
    return _name;
}

void person::setSurname(string surname) {
    _surname = surname;
}

string person::surname() {
    return _surname;
}

int person::setDob(Date dob) {
    return 1;
    return 0;
}

Date person::dob() {
    return _dob;
}
