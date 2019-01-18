//
// Created by Terekhin on 12/01/2019.
//
#pragma once
#include <sstream>


using namespace std;
class Date {
private:
    int _year;
    int _month;
    int _day;
public:
    Date(int year,int month,int day);

    int GetYear() const;

    int GetMonth() const;
    int GetDay() const;
};

Date ParseDate(istream& is);

ostream& operator <<(ostream& stream,const Date& d);
bool operator ==(const Date& l,const Date& r);

bool operator<(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);