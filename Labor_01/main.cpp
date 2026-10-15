
// global includes
#include <iostream>
#include <string>

// local includes
#include "customer.h"
#include "defs.h"
using namespace std;

// prototypes
// wechseln zwischen Person/Customer für jeweilge Ausgabe
// Vorher: void print(Person);
//  - Übergabe per Wert kopiert das Objekt. Wird ein Customer übergeben, wird
//    nur der Person-Anteil kopiert ("Object Slicing") -> Adresse geht verloren
//    und ein dynamic_cast auf Customer wäre unmöglich.
// Jetzt: void print(const Person& p);
//  - Referenz (&): keine Kopie, das Original-Objekt bleibt erhalten, daher
//    kann per dynamic_cast geprüft werden, ob es eigentlich ein Customer ist.
//  - const: print() darf das Objekt nur lesen, nicht verändern. Deshalb
//    müssen alle in print() aufgerufenen Getter als const deklariert sein.
//  - Person als Parametertyp: Customer erbt von Person, also kann eine
//    Funktion sowohl Person- als auch Customer-Objekte entgegennehmen.
void print(const Person& p);

int main()
{
    // local variables
    Customer aPerson;
    //Person bPerson;
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

    //bPerson.setName("John");
    //bPerson.setSurname("Doe");
    //bPerson.setDob(17, JUL, 1988);

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
    // wenn
    {
        cout << "Address: " << c->address().street << " ";
        cout << c->address().number << ", ";
        cout << c->address().postcode << " ";
        cout << c->address().city << ", ";
        cout << c->address().country << endl;
    }
}

/*
// Funktion zur Ausgabe von Personendetails
void print(Person aPerson)
{
    //prints out all the person's details
    cout<<"Name: "<<aPerson.name();
    cout<<" "<<aPerson.surname();
    cout<<" DoB: "<<aPerson.dob().day;
    cout<<"."<<aPerson.dob().month;
    cout<<"."<<aPerson.dob().year<<endl;
}

// Funktionsüberladung für die Ausgabe von Kundendetails
void print(Customer aPerson) {
    cout<<"Name: "<<aPerson.name();
    cout<<" "<<aPerson.surname();
    cout<<" DoB: "<<aPerson.dob().day;
    cout<<"."<<aPerson.dob().month;
    cout<<"."<<aPerson.dob().year<<endl;

    cout<<"Adresse: ";
    cout << aPerson.address().street << " ";
    cout << aPerson.address().number << ", ";
    cout << aPerson.address().postcode << " ";
    cout << aPerson.address().city << ", ";
    cout << aPerson.address().country << endl;
}
*/