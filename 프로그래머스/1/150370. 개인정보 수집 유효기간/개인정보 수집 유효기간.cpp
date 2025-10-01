#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> termsMap;

struct Date{
    int year;
    int month;
    int day;
    Date(){
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    Date(string str){
        year = stoi(str.substr(0, 4));
        month = stoi(str.substr(5, 7));
        day = stoi(str.substr(8, 10));
    }
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    Date todayD = Date(today);
    
    for (string t: terms){
        termsMap[t[0]] = (stoi(t.substr(2)));
    }
    
    for (int i = 0; i < privacies.size(); i++){
        string p = privacies[i];
        Date d = Date(p);
        int term = termsMap[p[11]];
        
        int y = term / 12;
        d.year += y;
        term %= 12;
        
        d.month += term;
        if (d.month > 12){
            d.month -= 12;
            d.year++;
        }
        
        if (d.year < todayD.year || 
           (d.year == todayD.year && d.month < todayD.month) ||
           (d.year == todayD.year && d.month == todayD.month && d.day <= todayD.day)){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}