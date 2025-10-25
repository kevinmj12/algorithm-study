#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int maxRScore = 0;

void solve(int n, vector<int> info, int rScore, int aScore, vector<int> ryan){
    if (ryan.size() == 10){
        if (rScore > aScore){
            ryan.push_back(n);
            if (rScore - aScore > maxRScore){
                maxRScore = rScore - aScore;
                answer = ryan;
            }
            else if (maxRScore > 0 && rScore - aScore == maxRScore){
                for (int i = 10; i >= 0; i--){
                    if (ryan[i] > answer[i]){
                        answer = ryan;
                        return;
                    }
                    else if (ryan[i] < answer[i]){
                        return;
                    }
                }
            }
        }
        return;
    }
    
    int round = ryan.size();
    
    // 화살을 안맞추는 경우
    ryan.push_back(0);
    
    if (info[round] > 0){
        solve(n, info, rScore, aScore + (10-round), ryan);    
    }
    else{
        solve(n, info, rScore, aScore, ryan);
    }
    
    // 화살을 맞춰 점수를 가져오는 경우
    if (n >= info[round]+1){
        ryan.pop_back();
        ryan.push_back(info[round]+1);
        solve(n-(info[round]+1), info, rScore + (10-round), aScore, ryan);
    }
}

vector<int> solution(int n, vector<int> info) {
    solve(n, info, 0, 0, {});
    
    if (answer.empty()){
        answer.push_back(-1);
    }
    
    return answer;
}