
// Implementierung der Person-Klasse

#include "person.h"

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

int Person::setDob(unsigned int day, MONTH month, int year) {
    // Month
    if (month < JAN or month > DEC)
        return ERROR;

    // Days
    if (day < 1 or day > 31)
        return ERROR;

    // Months, which end in 30 Days
    if (day == 31 and ( month == APR or month == JUN or month == SEP or  month == NOV))
        return ERROR;

    //Conditions for February
    if (month == FEB)
    {
        // Function for Leap-year
        bool leapYear = (year % 400 == 0) ||
                        (year % 4 == 0 && year != 0);

        if (day > 29)
            return ERROR;

        if (day == 29 && !leapYear)
            return ERROR;
    }

    _dob.day = day;
    _dob.month = month;
    _dob.year = year;
    return OK;

}

Date Person::dob() const {
    return _dob;
}
