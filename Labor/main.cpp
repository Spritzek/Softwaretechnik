
// global includes
#include <iostream>
#include <string>

// local includes
#include "customer.h"
#include "defs.h"
//#include "lib.h"
using namespace std;

// prototypes
void print(const Person& p);
/*
 * const: print() darf Objekt nur lesen. D.h. die Getter
 * müssen als Const deklariert sein, um sicherzustellen,
 * dass sich die Werte beim Lesen nicht ändern.
 *
 * Person: Parametertyp Person, da Customer von Person
 * erbt und sowieso die selben Parameter wie Person besitzt.
 *
 * &: Der Funktion wird nur eine Referenz übergeben. Das
 * stellt die Funktion von dynamic_cast sicher.
 */

int main()
{
    // local variables
    Customer aPerson;
    int error;

    // set person's details
    aPerson.setName("Joe");
    aPerson.setSurname("Bloggs");

    // Aufgabe 1: da die Methode keinen Rückgabewert mehr hat,
    // funktioniert diese Zuweisung nicht mehr.
    error = aPerson.setDob(
        17,     // day
        JUL,    // month
        1988    // year
    );
    aPerson.setAddress(
        "Hauptstraße",      // street
        21,                 // number
        "45220",            // postcode
        "Klein Bollersen",  // city
        "Deutschland"       // country
    );

    // check if dob is valid
    if( error)
    {
        cout<<"no such day"<<endl;
        return 1;
    }
    else
    {
        print(aPerson);
    }
    return 0;
}

void print(const Person& p)
{
    // Teil, der für Person und Customer gilt
    // Name:
    cout << "Name: ";
    cout << p.name()        << " ";
    cout << p.surname()     << " ";
    // Date of Birth:
    cout << "DoB: ";
    cout << p.dob().day     << ".";
    cout << p.dob().month   << ".";
    cout << p.dob().year    << endl;

    // Teil nur für Customer
    /*
     * &p beschreibt die Adresse des Objekts p
     * dynamic_cast: Laufzeitprüfung ob Objekt bei Adresse &p ein Customer
     * oder eine davon abgeleitete Klasse vorliegt
     * wenn der Cast gelingt (es liegt ein Customer Objekt vor), dann
     * wird c ein Pointer zugewiesen zum Objekt.
     * das wird von if als True interpretiert.
     * Andernfalls wird c ein NULL-Pointer zugewiesen.
     * Das wird von if als False interpretiert.
     */
    if (const Customer* c = dynamic_cast<const Customer*>(&p))
    {
        /*
         * Da c nur ein Pointer ist muss über "c->" angegeben
         * werden, dass das Objekt gemeint ist, auf welches
         * c zeigt.
         */
        cout << "Address: ";
        cout << c->address().street     << " ";
        cout << c->address().number     << ", ";
        cout << c->address().postcode   << " ";
        cout << c->address().city       << ", ";
        cout << c->address().country    << endl;
    }
}