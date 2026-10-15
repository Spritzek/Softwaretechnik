
// Implementierung der Customer-Klasse

#include "customer.h"

void Customer::setAddress(string street, uint number, string postcode, string city, string country) {
    _address.street     = street;
    _address.number     = number;
    _address.city       = city;
    _address.postcode   = postcode;
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
