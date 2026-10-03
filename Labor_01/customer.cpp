
#include "customer.h"

void Customer::setAddress(string street, uint number, string city, string postcode, string country) {
    _address.street = street;
    _address.number = number;
    _address.city = city;
    _address.postcode = postcode;
    _address.country = country;
}

Address Customer::address() {
    return _address;
}

void Customer::setId(uint id) {
    _id = id;
}

uint Customer::id() {
    return _id;
}
