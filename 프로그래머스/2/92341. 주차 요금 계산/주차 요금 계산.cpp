#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

struct Time{
    int hour;
    int minute;
    Time(){
        hour = 0;
        minute = 0;
    }
    Time(string s){
        hour = stoi(s.substr(0, 2));
        minute = stoi(s.substr(3));
    }
};

int getDuring(Time b, Time a){
    int time = 0;
    time += (a.hour - b.hour) * 60;
    time += (a.minute - b.minute);
    return time;
}

int getFee(int t, int a, int b, int c, int d){
    if (t <= a){
        return b;
    }
    t -= a;
    double tmp = (double)t/c;
    return b + ceil(tmp) * d;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    set<int> vehicle;
    vector<bool> isExit(10000, true);
    map<int, Time> recordMap;
    map<int, int> totalTime;
    
    for (string s: records){
        Time t = Time(s.substr(0, 5));
        int n = stoi(s.substr(6, 4));
        bool type = s.substr(11) == "IN" ? 0 : 1;
        vehicle.insert(n);
        
        if (!type){
            recordMap[n] = t;
            isExit[n] = false;
        }
        else{
            int time = getDuring(recordMap[n], t);
            isExit[n] = true;
            if (totalTime.find(n) == totalTime.end()){
                totalTime[n] = time;
            }
            else{
                totalTime[n] += time;
            }            
        }
    }
    
    for (auto it = vehicle.begin(); it != vehicle.end(); it++){
        int n = *it;
        if (!isExit[n]){
            if (totalTime.find(n) == totalTime.end()){
                totalTime[n] = getDuring(recordMap[n], Time("23:59"));
            }
            else{
                totalTime[n] += getDuring(recordMap[n], Time("23:59"));
            }
        }
        answer.push_back(getFee(totalTime[n], fees[0], fees[1], fees[2], fees[3]));
    }
    
    
    return answer;
}