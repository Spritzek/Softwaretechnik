
#pragma once
#include <string>
using namespace std;

#define OK      0
#define ERROR   1

enum MONTH {
    JAN, FEB, MAR, APR,
    MAY, JUN, JUL, AUG,
    SEP, OCT, NOV, DEC
};

struct Date
{
    int day;
    MONTH month;
    int year;
};

struct Address
{
    string street;
    unsigned int number;
    string postcode;
    string city;
    string country;
};
