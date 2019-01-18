#pragma once
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <functional>
#include <exception>
#include <string>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s);
template<class T>
ostream& operator << (ostream& os, const set<T>& s);

template<class K,class V>
ostream& operator << (ostream& os, const map<K, V>& m);

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

class TestRunner {
public:
    void RunTest(function<void()> func, const string& test_name);

    ~TestRunner();

private:
    int fail_count = 0;
};

//Definition

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
};
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
};

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
};


template<typename T, typename U>
void AssertEqual(const T& t, const U& u,
                 const string& hint)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u
           << " hint: " << hint;
        throw runtime_error(os.str());
    }
};
