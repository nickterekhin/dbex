#include "node.h"

using namespace std;

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &op, const shared_ptr<Node> &left,const shared_ptr<Node> &right):_op(op),_left(left),_right(right){

}
bool LogicalOperationNode::Evaluate(const Date &date,const string &s) const {
    if(_op==LogicalOperation::And) {
        bool l = _left->Evaluate(date, s);
        bool r = _right->Evaluate(date, s);
        return l && r;
    }

    return _left->Evaluate(date,s) || _right->Evaluate(date,s);
}
DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date):_date(date) {
    _cmp = cmp;
}
bool DateComparisonNode::Evaluate(const Date &date,const string &s) const {

    if(_cmp==Comparison::NotEqual)
        return date!=_date;
    if(_cmp==Comparison::Equal)
        return date==_date;
    if(_cmp==Comparison::GreaterOrEqual)
        return date>=_date;
    if(_cmp==Comparison::Greater)
        return date>_date;
    if(_cmp==Comparison::LessOrEqual)
        return date<=_date;
    if(_cmp==Comparison::Less)
        return date<_date;

    return false;
}

EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event):_event(event) {
    _cmp = cmp;
}

bool EventComparisonNode::Evaluate(const Date &date,const string &s) const {
    int c = s.compare(_event);
    if(_cmp==Comparison::Equal)
        return c==0;
    if(_cmp==Comparison::NotEqual)
        return c!=0;
    if(_cmp==Comparison::Less)
        return c<0;
    if(_cmp==Comparison::Greater)
        return c>0;
    if(_cmp==Comparison::LessOrEqual)
        return c<0 || c==0;
    if(_cmp==Comparison::GreaterOrEqual)
        return c>0 || c==0;


    return false;
}

bool EmptyNode::Evaluate(const Date &date, const string &s) const {
    return true;
}