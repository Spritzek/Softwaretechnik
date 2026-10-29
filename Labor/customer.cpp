
// Implementierung der Customer-Klasse

#include "customer.h"
#include <stdexcept>

void Customer::setAddress(string street, uint number, string postcode, string city, string country) {
    if (postcode.length() != 5) throw length_error(ERRORMSG);

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
