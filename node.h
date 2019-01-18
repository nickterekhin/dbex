#pragma once
#include "date.h"
#include <memory>

using namespace std;

enum LogicalOperation{
    And,
    Or
};
enum Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};
class Node{
public:
    virtual ~Node(){}
    virtual bool Evaluate(const Date &date,const string &s) const =0;
protected:
    Comparison _cmp;
};

class EmptyNode:public Node{
public:
    virtual bool Evaluate(const Date &date,const string &s) const override;
};
class DateComparisonNode:public Node{
public:
    DateComparisonNode(const Comparison &cmp,const Date &date);
    bool Evaluate(const Date &date,const string &s) const override;
private:
    Date _date;
};
class EventComparisonNode:public Node{
public:
    EventComparisonNode(const Comparison &cmp,const string &event);
    bool Evaluate(const Date &date,const string &s) const override;
private:
    const string _event;
};
class LogicalOperationNode:public Node{
public:
    explicit LogicalOperationNode(const LogicalOperation &op, const shared_ptr<Node> &left, const shared_ptr<Node> &right);
    bool Evaluate(const Date &date,const string &s) const override;
private:
    LogicalOperation _op;
    shared_ptr<Node> _left;
    shared_ptr<Node> _right;
};


