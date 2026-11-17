
#include "customer.h"

void Customer::init() {
    Person::init();
    _address.street   = "Musterstraße";
    _address.number   = 1;
    _address.postcode = "12345";
    _address.city     = "Musterstadt";
    _address.country  = "Deutschland";
}

void Customer::setAddress(string street, uint number, string postcode, string city, string country) {
    _address.street     = street;
    _address.number     = number;
    _address.postcode   = postcode;
    _address.city       = city;
    _address.country    = country;
}

Address Customer::address() const {
    return _address;
}

void Customer::setId(uint id) {
    _id = id;
}

uint Customer::id() const {
    return _id;
}
