#include <sys/types.h>

#include "person.h"

class Customer: public Person {
private:
    Address _address = {};
    unsigned int _id;
public:
    void setAddress(string street, uint number, string city, string postcode, string country);
    Address address();
    void setId(uint id);
    uint id();
};
