#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int timeToSec(string time){
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6));
    
    return hour*3600 + minute*60 + second;
}

string timeToStr(int sec){
    string hour = to_string(sec / 3600);
    sec %= 3600;
    string minute = to_string(sec / 60);
    sec %= 60;
    string second = to_string(sec);
    
    if (hour.length() == 1){
        hour = "0"+hour;
    }
    if (minute.length() == 1){
        minute = "0"+minute;
    }
    if (second.length() == 1){
        second = "0"+second;
    }
    
    return hour + ":" + minute + ":" + second;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTime = timeToSec(play_time);
    int adTime = timeToSec(adv_time);
    
    vector<int> times(362440, 0);
    
    for (string log: logs){
        string startStr = log.substr(0, 8);
        string endStr = log.substr(9);
        int start = timeToSec(startStr);
        int end = timeToSec(endStr);
        
        for (int i = start; i < end; i++){
            times[i]++;
        }
    }
    
    long adPlayTime = 0;
    
    for (int i = 0; i < adTime; i++){
        adPlayTime += times[i]; 
    }
    
    int answerSec = 0;
    long maxAdPlayTime = adPlayTime;
    
    int startTime = 0;
    int endTime = adTime;
    int lastTime = playTime-adTime;
    
    while (true){
        adPlayTime -= times[startTime];
        adPlayTime += times[endTime];
        startTime++;
        endTime++;
        
        if (endTime > playTime){
            break;
        }
        
        if (adPlayTime > maxAdPlayTime){
            maxAdPlayTime = adPlayTime;
            answerSec = startTime;
        }
    }
    
    answer = timeToStr(answerSec);
    
    return answer;
}