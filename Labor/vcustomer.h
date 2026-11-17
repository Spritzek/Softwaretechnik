
/*
 * VCustomer ist der Contract-Checker des Customer-"Servers".
 * Werden die Methoden setName(), setSurname(), setDob() oder setAddress()
 * aufgerufen, so werden die vom Client übergebenen Werte zunächst mit
 * assert() geprüft. Sollte dabei nichts schieflaufen, wird die Methode
 * der Basisklasse ausgeführt. Im Anschluss wird mit assert() noch geprüft,
 * ob die Werte im Basisobjekt auch den übergebenen Werten entsprechen.
 *
 * Fehlt ein assert() fehl (eine Condition ist != wahr), bricht das Programm
 * sofort ab. Asserts können nicht gefangen werden. Der Sinn dahinter besteht
 * darin, dass Vertragsbrüche garantierte Programmierfehler darstellen.
 */

#pragma once
#include "customer.h"

class VCustomer : public Customer{
public:
    void setName(string name)
        override;
    void setSurname(string surname)
        override;
    void setDob(unsigned int day, MONTH month, int year)
        override;
    void setAddress(string street, uint number, string postcode, string city, string country)
        override;
};