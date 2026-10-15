
// global includes
#include <iostream>
#include <string>

// local includes
#include "customer.h"
#include "defs.h"
using namespace std;

// prototypes
void print(const Person& p);
// const: print() darf Objekt nur lesen. D.h. die Getter
// müssen als Const deklariert sein, um sicherzustellen,
// dass sich die Werte beim Lesen nicht ändern.
//
// Person: Parametertyp Person, da Customer von Person
// erbt und sowieso die selben Parameter wie Person besitzt.
//
// &: Der Funktion wird nur eine Referenz übergeben. Das
// stellt die Funktion von dynamic_cast sicher.

int main()
{
    // local variables
    Customer aPerson;
    int error;

    // set person's details
    aPerson.setName("Joe");
    aPerson.setSurname("Bloggs");
    error = aPerson.setDob(17, JUL, 1988);
    aPerson.setAddress(
        "Hauptstraße",
        21,
        "45220",
        "Klein Bollersen",
        "Deutschland"
    );

    // check if day matches month
    if( error)
    {
        // oops - no such day, what shall I do?!
        cout<<"no such day"<<endl;
        //c++ Return Value für fehlerhaft ausgeführtes Programm
        return 1;
    }
    else
    {
        // everything is fine, carry on ...
        print(aPerson);
        //print(bPerson);
    }
    //c++ typischer Return Value für ein sauber ausgeführtes Programm
    return 0;
}

void print(const Person& p)
{
    // Teil, der für Person und Customer gilt
    cout << "Name: " << p.name();
    cout << " " << p.surname();
    cout << " DoB: " << p.dob().day;
    cout << "." << p.dob().month;
    cout << "." << p.dob().year << endl;

    // Teil nur für Customer
    if (const Customer* c = dynamic_cast<const Customer*>(&p))
    // &p beschreibt die Adresse des Objekts p
    // dynamic_cast: Laufzeitprüfung ob Objekt bei Adresse &p ein Customer
    // oder eine davon abgeleitete Klasse vorliegt
    // wenn der Cast gelingt (es liegt ein Customer Objekt vor), dann
    // wird c ein Pointer zugewiesen zum Objekt.
    // das wird von if als True interpretiert.
    // Andernfalls wird c ein NULL-Pointer zugewiesen.
    // Das wird von if als False interpretiert.
    {
        cout << "Address: " << c->address().street << " ";
        cout << c->address().number << ", ";
        cout << c->address().postcode << " ";
        cout << c->address().city << ", ";
        cout << c->address().country << endl;
    }
}