
// Deklaration der Person-Klasse

#pragma once
#include "defs.h"
#include <string>
using namespace std;

class Person {
private:
    string _name;
    string _surname;
    Date _dob = {};
public:
    // Funktion zum Setzen des Vornamens
    void setName(string name);
    // Funktion zum Abrufen des Vornamens
    string name();
    // Funktion zum Setzen des Nachnamens
    void setSurname(string surname);
    // Funktion zum Abrufen des Nachnamens
    string surname();
    // Funktion zum Setzen und Prüfen des Geburtsdatums
    int setDob(unsigned int day, MONTH month, int year);
    // Funktion zum Abrufen des Geburtsdatums
    Date dob();
};
