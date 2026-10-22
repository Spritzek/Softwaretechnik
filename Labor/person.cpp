
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

/*
 * Anstelle von return Values werden invalid_argument exceptions erhoben.
 * Daher wurde der Return-Type der Methode auf void geändert.
 */
void Person::setDob(unsigned int day, MONTH month, int year) {
    // Month
    if (month < JAN or month > DEC)
        throw invalid_argument(ERRORMSG);

    // Days
    if (day < 1 or day > 31)
        throw invalid_argument(ERRORMSG);

    // Months, which end in 30 Days
    if (day == 31 and ( month == APR or month == JUN or month == SEP or  month == NOV))
        throw invalid_argument(ERRORMSG);

    //Conditions for February
    if (month == FEB)
    {
        // Function for Leap-year
        bool leapYear = (year % 400 == 0) ||
                        (year % 4 == 0 && year != 0);

        if (day > 29)
            throw invalid_argument(ERRORMSG);

        if (day == 29 && !leapYear)
            throw invalid_argument(ERRORMSG);
    }

    _dob.day    = day;
    _dob.month  = month;
    _dob.year   = year;
}

Date Person::dob() const {
    return _dob;
}
