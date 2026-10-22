
// Implementierung der Person-Klasse

#include "person.h"
#define TEST "ERROR"

void Person::setName(string name) {
    _name = name;
}

string Person::name() const {
    return _name;
}

void Person::setSurname(string surname) {
    _surname = surname;
}

string Person::surname() const {
    return _surname;
}

void Person::setDob(unsigned int day, MONTH month, int year) {
    // Month
    if (month < JAN or month > DEC) {
        throw ERROR;
    }

    // Days
    if (day < 1 or day > 31)
        throw ERROR;

    // Months, which end in 30 Days
    if (day == 31 and ( month == APR or month == JUN or month == SEP or  month == NOV))
        throw ERROR;

    //Conditions for February
    if (month == FEB)
    {
        // Function for Leap-year
        bool leapYear = (year % 400 == 0) ||
                        (year % 4 == 0 && year != 0);

        if (day > 29)
            throw ERROR;

        if (day == 29 && !leapYear)
            throw ERROR;
    }

    _dob.day    = day;
    _dob.month  = month;
    _dob.year   = year;
}

Date Person::dob() const {
    return _dob;
}
