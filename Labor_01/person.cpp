
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
    bool sj = false;
    if (year >= 1804 && (year - 1804)%4 == 0) {
        sj = true;
    }
    if (year >= 1804 && (
        (month == 0 and day <= 31) ||
        (month == 1 and day <= 27) ||
        (month == 1 and day == 28 and sj == true) ||
        (month == 2 and day <= 31) ||
        (month == 3 and day <= 30) ||
        (month == 4 and day <= 31) ||
        (month == 5 and day <= 30) ||
        (month == 6 and day <= 31) ||
        (month == 7 and day <= 31) ||
        (month == 8 and day <= 30) ||
        (month == 9 and day <= 31) ||
        (month == 10 and day <= 30) ||
        (month == 11 and day <= 31)
    )) {
        _dob.day = day;
        _dob.month = month;
        _dob.year = year;
        return 0;
    }
    return 1;
}

Date Person::dob() {
    return _dob;
}
