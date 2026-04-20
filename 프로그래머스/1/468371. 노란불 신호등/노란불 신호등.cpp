#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    int t = 0;
    int maxT = 1;
    vector<int> nextChange(signals.size());
    vector<int> status(signals.size());
    
    for (int i = 0; i < signals.size(); i++){
        maxT = lcm(maxT, signals[i][0] + signals[i][1] + signals[i][2]);
        nextChange[i] = signals[i][0];
    }
    
    for (int t = 1; t <= maxT; t++){
        for (int i = 0; i < signals.size(); i++){
            if (t == nextChange[i]){
                status[i] = (status[i] + 1) % 3;
                nextChange[i] += signals[i][status[i]];
            }
        }
        bool allY = true;
        for (int i = 0; i < signals.size(); i++){
            if (status[i] != 1){
                allY = false;
                break;
            }
        }
        
        if (allY){
            answer = t+1;
            break;
        }
    }
    
    return answer;
}