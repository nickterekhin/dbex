#pragma once
#include "date.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <deque>
#include <functional>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;
class Database {
public:

    void Add(const Date& date, const string& event);

    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);

    vector<string> FindIf(function<bool(const Date& date, const string& event)> predicate) const;

    string Last(const Date &date) const;

    void Print(ostream& os) const;

private:
    map<Date,set<string>> _events;
    map<Date,deque<set<string>::const_iterator>> _index;
};

