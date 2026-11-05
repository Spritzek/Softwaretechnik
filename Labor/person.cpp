
// Implementierung der Person-Klasse

#include "person.h"
#include <stdexcept>

#include "exceptions.h"
#define TEST "ERROR"
using namespace std;

void Person::init() {
    _name       = "Max";
    _surname    = "Mustermann";
    _dob.day    = 1;
    _dob.month  = JAN;
    _dob.year   = 2000;
}

void Person::setName(string name) {
    _name = name;
    if (ranges::find_if(_name, isdigit) != _name.end()) {
        throw digit_in_name(ERRORMSG);
    }
}

string Person::name() const {
    return _name;
}

void Person::setSurname(string surname) {
    _surname = surname;
    if (ranges::find_if(_surname, isdigit) != _surname.end()) {
        throw digit_in_name(ERRORMSG);
    }
}

string Person::surname() const {
    return _surname;
}

/*
 * Anstelle von return Values werden invalid_argument exceptions erhoben.
 * Daher wurde der Return-Type der Methode auf void geändert.
 */
void Person::setDob(unsigned int day, MONTH month, int year) {
    // Month
    if (month < JAN or month > DEC)
        throw date_non_existent(ERRORMSG);

    // Days
    if (day < 1 or day > 31)
        throw date_non_existent(ERRORMSG);

    // Months, which end in 30 Days
    if (day == 31 and ( month == APR or month == JUN or month == SEP or  month == NOV))
        throw date_non_existent(ERRORMSG);

    //Conditions for February
    if (month == FEB)
    {
        // Function for Leap-year
        bool leapYear = (year % 400 == 0) ||
                        (year % 4 == 0 && year != 0);

        if (day > 29)
            throw date_non_existent(ERRORMSG);

        if (day == 29 && !leapYear)
            throw date_non_existent(ERRORMSG);
    }

    _dob.day    = day;
    _dob.month  = month;
    _dob.year   = year;
}

Date Person::dob() const {
    return _dob;
}
