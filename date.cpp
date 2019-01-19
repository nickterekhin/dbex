//
// Created by Terekhin on 12/01/2019.
//

#include <string>
#include <iomanip>
#include "date.h"
#include <vector>

using namespace std;


    Date::Date(int year,int month,int day)
    {
        _year = year;
        if (month < 1 || month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(_month));
        _month = month;
       if (day < 1 || day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(_day));
        _day=day;


    }

    int Date::GetYear() const
    {
        return _year;
    }
    int Date::GetMonth() const{
        return _month;
    }
    int Date::GetDay() const{
        return _day;
    }
    ostream& operator <<(ostream& stream,const Date& d)
    {
        stream<<setw(4)<<setfill('0')<<to_string(d.GetYear())<<"-"<<setw(2)<<setfill('0')<<to_string(d.GetMonth())<<"-"<<setw(2)<<setfill('0')<<to_string(d.GetDay());
        return stream;
    }
    bool operator ==(const Date& l,const Date& r)
    {
        return l.GetDay() == r.GetDay() && l.GetMonth() == r.GetMonth() && l.GetYear() == r.GetYear();

    }

bool operator<(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()}<vector<int>{rhs.GetYear(),rhs.GetMonth(),rhs.GetDay()};
}
bool operator!=(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()}!=vector<int>{rhs.GetYear(),rhs.GetMonth(),rhs.GetDay()};
    }
bool operator>=(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()}>=vector<int>{rhs.GetYear(),rhs.GetMonth(),rhs.GetDay()};
    }
bool operator>(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()}>vector<int>{rhs.GetYear(),rhs.GetMonth(),rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()}<=vector<int>{rhs.GetYear(),rhs.GetMonth(),rhs.GetDay()};
}

Date ParseDate(istream &is){
        string date;
        is>>date;
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw invalid_argument("Incorrect date format:"+date);
    }
    return {year, month, day};
    }