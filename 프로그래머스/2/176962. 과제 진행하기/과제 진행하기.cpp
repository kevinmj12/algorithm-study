#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int sToMinutes(string s){
    int min = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3));
    
    return 60*min + sec;
}

bool compare(vector<string> a, vector<string> b){
    int ma = sToMinutes(a[1]);
    int mb = sToMinutes(b[1]);
    return ma < mb;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), compare);
    
    stack<pair<int, string>> subjectStack;
    int startTime = 0;
    
    for (int i = 0; i < plans.size(); i++){
        string subject = plans[i][0];
        int time = sToMinutes(plans[i][1]);
        int needTime = stoi(plans[i][2]);
        
        if (subjectStack.empty()){
            subjectStack.push({needTime, subject});
            startTime = time;
        }
        else{
            while (!subjectStack.empty()){
                if (time - startTime >= subjectStack.top().first){
                    startTime += subjectStack.top().first;
                    answer.push_back(subjectStack.top().second);
                    subjectStack.pop();
                }
                else{
                    subjectStack.top().first -= (time - startTime);
                    break;
                }
            }
            startTime = time;
            subjectStack.push({needTime, subject});
        }
    }
    
    while (!subjectStack.empty()){
        answer.push_back(subjectStack.top().second);
        subjectStack.pop();
    }
    
    return answer;
}