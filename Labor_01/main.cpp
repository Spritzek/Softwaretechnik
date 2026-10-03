
// global includes
#include <iostream>
#include <string>

// local includes
#include "customer.h"
#include "defs.h"
using namespace std;

// prototypes
// wechseln zwischen Person/Customer für jeweilge Ausgabe
void print(Person);

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
    }
    //c++ typischer Return Value für ein sauber ausgeführtes Programm
    return 0;
}

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