
// Deklaration der Customer-Klasse

#pragma once
#include "person.h"
#include <sys/types.h>
#include <string>

class Customer: public Person {
private:
    Address _address;
    unsigned int _id;
public:
    // Hinweis: address() und id() sind const, damit sie in print() über
    // den const Customer* aus dem dynamic_cast aufgerufen werden können.
    // Funktion zum setzen der Adresse
    void setAddress(string street, uint number, string city, string postcode, string country);
    // Funktion zum Abrufen der Adresse
    Address address() const;
    // Funktion zum Setzen der ID
    void setId(uint id);
    // Funktion zum Abrufen der ID
    uint id() const;
};
