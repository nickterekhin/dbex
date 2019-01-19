#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string &event){

    if (event.size()==0) {
        return;
    }
    auto res =  _events[date].insert(event);
    if(res.second)
        _index[date].push_back(res.first);

}
string Database::Last(const Date &date) const{
    //throw invalid_argument("");
    auto it = _events.upper_bound(date);
    if(it!=_events.begin()){
        if(!(--it)->second.empty()) {
            stringstream _event;
            _event<<it->first<<" "<<(*_index.at(it->first).back());
            return _event.str();
        }
    }
    throw invalid_argument("No entries");
    //return "No entries";

}

void Database::Print(ostream& os) const
{
    for(auto &event: _events)
    {
        for(auto e:_index.at(event.first))
        {
            os<<event.first<<" "<<(*e)<<endl;
        }
    }
}
int Database::RemoveIf(function<bool(const Date& date, const string& event)> predicate){

    int qty = 0;
    for(auto it=_events.begin();it!=_events.end();)
    {
        auto it_events_to_remove = stable_partition(_index.at(it->first).begin(),_index.at(it->first).end(),[it,predicate](const auto &event){
            return predicate(it->first,*event);
        });
        qty += it_events_to_remove - _index.at(it->first).begin();

        for(auto it_sub = _index.at(it->first).begin();it_sub!=it_events_to_remove;++it_sub)
        {
            it->second.erase(*it_sub);
        }

        _index.at(it->first).erase(_index.at(it->first).begin(), it_events_to_remove);


        if(it->second.empty()) {
            _index.erase(it->first);
            it = _events.erase(it);
        }
        else
            ++it;
    }


 return qty;
}

vector<string> Database::FindIf(function<bool(const Date& date, const string& event)> predicate) const{

    vector<string> res;
    for(auto it = _index.begin();it!=_index.end();++it)
    {
        for(auto it_event = it->second.begin();it_event!=it->second.end();++it_event)
        {
            if(predicate(it->first,**it_event))
            {
                stringstream _event;
                _event<<it->first<<" "<<**it_event;
                res.push_back(_event.str());
            }
        }

    }

 return res;
}