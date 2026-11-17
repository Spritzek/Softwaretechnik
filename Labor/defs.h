
#pragma once
#include <string>
using namespace std;

#define OK      0
#define ERROR   1
#define ERRORMSG "ERROR"

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
inline bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}

struct Address
{
    string street;
    unsigned int number;
    string postcode;
    string city;
    string country;
};
/*
inline bool operator==(const Address& left, const Address& right) {
    return left.street == right.street &&
           left.number == right.number &&
           left.postcode == right.postcode &&
           left.city == right.city &&
           left.country == right.country;
}
 */