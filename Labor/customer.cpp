
// Implementierung der Customer-Klasse

#include "customer.h"
#include <stdexcept>

#include "exceptions.h"

void Customer::init() {
    Person::init();
    _address.street   = "Musterstraße";
    _address.number   = 1;
    _address.postcode = "12345";
    _address.city     = "Musterstadt";
    _address.country  = "Deutschland";
}

void Customer::setAddress(string street, uint number, string postcode, string city, string country) {
    if (ranges::find_if_not(postcode, isdigit) != postcode.end()) {
        throw letter_in_number(ERRORMSG);
    };
    if (postcode.length() != 5) throw postcode_length_error(ERRORMSG);
    if (
        ranges::find_if(street, isdigit) != street.end() ||
        ranges::find_if(city, isdigit) != city.end() ||
        ranges::find_if(country, isdigit) != country.end()
        ){
        throw digit_in_word(ERRORMSG);
    }

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
