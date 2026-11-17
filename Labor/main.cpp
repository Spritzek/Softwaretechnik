
// includes
#include <iostream>     // global
#include "customer.h"   // local
#include "defs.h"       // local
#include "vcustomer.h"  // local

// prototypes
static void print(const Customer* p);

int main() {

    /*
     * In diesem Labor stellt die main() Methode den Client dar.
     * Der Client soll die Methoden des Servers aufrufen und
     * der Server soll die Aufrufe mithilfe des Contract-Checkers
     * überprüfen.
     */

    Customer* aPerson = new VCustomer();

    aPerson->setName("Joe");
    aPerson->setSurname("Bloggs");
    aPerson->setDob(12, JUL, 1988);
    aPerson->setAddress(
        "Hauptstraße",      // street
        21,                   // number
        "45220",            // postcode
        "Klein Bollersen",  // city
        "Deutschland"       // country
    );

    print(aPerson);

    // --- Speicher freigeben ---
    delete aPerson;
    // --------------------------

    return 0;
}

/*
 * Annahme für Labor_03:
 * Es werden keine Objekte der Klasse Person übergeben!
 */
static void print(const Customer* p)
{
    // Name:
    cout << "Name: ";
    cout << p->name()        << " ";
    cout << p->surname()     << " ";

    // Date of Birth:
    cout << "DoB: ";
    cout << p->dob().day     << ".";
    cout << p->dob().month   << ".";
    cout << p->dob().year    << endl;

    // Address:
    cout << "Address: ";
    cout << p->address().street     << " ";
    cout << p->address().number     << ", ";
    cout << p->address().postcode   << " ";
    cout << p->address().city       << ", ";
    cout << p->address().country    << endl;
}