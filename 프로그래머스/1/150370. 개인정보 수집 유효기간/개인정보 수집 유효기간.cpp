#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct Date{
    int year;
    int month;
    int date;
    
    Date(){
        year = 0;
        month = 0;
        date = 0;
    }
    Date(string s){
        year = stoi(s.substr(0, 4));
        month = stoi(s.substr(5, 2));
        date = stoi(s.substr(8, 2));
    }
    Date(int y, int m, int d){
        year = y;
        month = m;
        date = d;
    }
};

void addMonth(Date& d, int m){
    d.month += m;
    d.date--;
    if (d.date == 0){
        d.date = 28;
        d.month--;
    }

    if (d.month >= 13){
        d.year += (d.month-1) / 12;
        d.month = (d.month-1) % 12 + 1;
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    Date t = Date(today);
    map<char, int> termsMap;
    for (string term: terms){
        termsMap.insert({term[0], stoi(term.substr(2))});
    }
    
    for (int i = 0; i < privacies.size(); i++){
        string p = privacies[i];
        Date d = Date(p.substr(0, 10));
        addMonth(d, termsMap[p[11]]);
        
        if (d.year < t.year ||
           (d.year == t.year && d.month < t.month) || 
           (d.year == t.year && d.month == t.month && d.date < t.date)){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}