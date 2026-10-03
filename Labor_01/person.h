#include <string>

#include "defs.h"
using namespace std;
#pragma once

class person {
private:
    string _name;
    string _surname;
    Date _dob = {};
public:
    void setName(string name);
    string name();
    void setSurname(string surname);
    string surname();
    int setDob(Date dob);
    Date dob();
};
