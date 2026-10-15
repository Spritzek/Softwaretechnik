
// Deklaration der Person-Klasse

#pragma once
#include "defs.h"
#include <string>
using namespace std;

class Person {
private:
    string  _name;
    string  _surname;
    Date    _dob = {};
public:
    /*
     * Virtueller Destruktor: Dadurch wird Person zu einer polymorphen Klasse.
     * Das ist Voraussetzung für dynamic_cast<const Customer*> in print(),
     * da dynamic_cast zur Laufzeit den tatsächlichen Typ prüfen muss (RTTI).
     * Außerdem wird so beim Löschen eines Customer über einen Person-Zeiger
     * auch der Customer-Destruktor korrekt aufgerufen.
     */
    virtual ~Person() = default;
    /*
     * Hinweis zu const bei den Abruf-Funktionen:
     * Das const hinter der Funktion garantiert, dass sie das Objekt nicht verändert.
     * Nur solche Funktionen dürfen auf einem const-Objekt bzw. über eine
     * const-Referenz aufgerufen werden, wie in print(const Person& p).
     * Die Setter bleiben ohne const, da sie das Objekt verändern.
     */

    //Funktion zum Setzen des Vornamens
    void setName(string name);

    // Funktion zum Abrufen des Vornamens
    string name() const;

    // Funktion zum Setzen des Nachnamens
    void setSurname(string surname);

    // Funktion zum Abrufen des Nachnamens
    string surname() const;

    // Funktion zum Setzen und Prüfen des Geburtsdatums
    int setDob(unsigned int day, MONTH month, int year);

    // Funktion zum Abrufen des Geburtsdatums
    Date dob() const;
};
