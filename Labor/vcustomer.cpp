
/*
 * VCustomer ist der Contract-Checker des Customer-"Servers".
 * Werden die Methoden setName(), setSurname(), setDob() oder setAddress()
 * aufgerufen, so werden die vom Client übergebenen Werte zunächst mit
 * assert() geprüft. Sollte dabei nichts schieflaufen, wird die Methode
 * der Basisklasse ausgeführt. Im Anschluss wird mit assert() noch geprüft,
 * ob die Werte im Basisobjekt auch den übergebenen Werten entsprechen.
 *
 * Der Contract-Checker überschreibt die Methoden der Basisklasse,
 * sodass diese explizit durch den Contract-Checker aufgerufen werden müssen
 * (z.B. Customer::setName()).
 *
 * Schlägt ein assert() fehl (eine Condition ist != wahr), bricht das Programm
 * sofort ab. Asserts können nicht gefangen werden. Der Sinn dahinter besteht
 * darin, dass Vertragsbrüche garantierte Programmierfehler darstellen sollen.
 */

// includes
#include <string>       // global
#include <cassert>      // global
#include "vcustomer.h"  // local
#include "defs.h"       // local

namespace {
    bool isLeapYear(const int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    bool isValidDate(const int day, const int month, const int year) {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDay = days[month - 1];
        if (month == 2 && isLeapYear(year)) maxDay = 29;
        return day <= maxDay;
    }
}

void VCustomer::setName(const string name) {
    assert(!name.empty());
    Customer::setName(name);
    assert(this->name() == name);
}

void VCustomer::setSurname(const string surname) {
    assert(!surname.empty());
    Customer::setSurname(surname);
    assert(this->surname() == surname);
}
void VCustomer::setDob(const unsigned int day, const MONTH month, const int year) {
    assert(isValidDate(day, month, year) && "Ungültiges Datum");
    Customer::setDob(day, month, year);
    assert(this->dob() == Date(day, month, year));
}
void VCustomer::setAddress
(
    const string street,
    const uint number,
    const string postcode,
    const string city,
    const string country
) {
    assert
    (
        !street.empty()         &&
        number != 0             &&
        !postcode.empty()       &&
        !city.empty()           &&
        !country.empty()        &&
        //----- Überprüfung ob Länge der Postleitzahl zulässig ist -----
        postcode.length() == 5 && "Postleitzahl ungültig"
        //--------------------------------------------------------------
    );
    Customer::setAddress(street, number, postcode, city, country);
    assert
    (
        this->address().street   == street   &&
        this->address().number   == number   &&
        this->address().postcode == postcode &&
        this->address().city     == city     &&
        this->address().country  == country
    );
}