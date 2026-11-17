
// Deklaration der Customer-Klasse

#pragma once
#include "person.h"
#include <sys/types.h>
#include <string>

class Customer: public Person {
private:
    Address         _address;
    unsigned int    _id;
public:

    void init() override;

    virtual void setAddress(
        string  street,
        uint    number,
        string  postcode,
        string  city,
        string  country
    );

    // Funktion zum Abrufen der Adresse
    Address address() const;

    // Funktion zum Setzen der ID
    void setId(uint id);

    // Funktion zum Abrufen der ID
    uint id() const;
};
