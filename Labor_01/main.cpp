// global includes
#include <iostream>
#include <string>
// local includes
#include "person.h"
#include "defs.h"
using namespace std;
// prototypes
void print(Person);
// main function, no need to return anything
int main()
{
    // local variables
    Person aPerson;
    int error;
    // set person's details
    aPerson.setName("Joe");
    aPerson.setSurname("Bloggs");
    error = aPerson.setDob(17, JUL, 1988);
    // check if day matches month
    if( error)
    {
        // oops - no such day, what shall I do?!
        cout<<"no such day"<<endl;
    }
    else
    {
        // everything is fine, carry on ...
        print(aPerson);
    }
    return 0;
}
void print(Person aPerson)
{
    //prints out all the person's details
    cout<<"Name: "<<aPerson.name();
    cout<<" "<<aPerson.surname();
    cout<<" DoB: "<<aPerson.dob().day;
    cout<<"."<<aPerson.dob().month;
    cout<<"."<<aPerson.dob().year<<endl;
}