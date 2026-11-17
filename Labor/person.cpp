
#include "person.h"

#include <utility>
using namespace std;

void Person::init() {
    _name       = "Max";
    _surname    = "Mustermann";
    _dob.day    = 1;
    _dob.month  = JAN;
    _dob.year   = 2000;
}

void Person::setName(string name) {
    _name = std::move(name);
}

string Person::name() const {
    return _name;
}

void Person::setSurname(string surname) {
    _surname = std::move(surname);
}

string Person::surname() const {
    return _surname;
}

void Person::setDob(const uint day, const MONTH month, const int year) {
    _dob.day    = day; // NOLINT(*-narrowing-conversions)
    _dob.month  = month;
    _dob.year   = year;
}

Date Person::dob() const {
    return _dob;
}
