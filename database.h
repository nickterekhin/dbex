#pragma once
#include "date.h"
#include <iostream>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;
class Database {
public:

    void Add(const Date& date, const string& event);


    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);

    set<string> FindIf(function<bool(const Date& date, const string& event)> predicate) const;

    string Last(const Date &date) const;

    void Print(ostream& os) const;

private:
    map<Date,set<string>> _events;
    map<Date,vector<set<string>::const_iterator>> _index;
};

