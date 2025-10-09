#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxAnswer = 0;
vector<int> answer;

void backtracking(int n, vector<int> info, int i, int aScore, int lScore, vector<int> v){
    if (i == 11){
        if (n){
            v.back() += n;
        }
        
        if (lScore - aScore > maxAnswer){
            maxAnswer = lScore-aScore;
            answer = v;
        }
        else if (maxAnswer > 0 && lScore - aScore == maxAnswer){
            int right = 10;
            while (right >= 0){
                if (v[right] > answer[right]){
                    answer = v;
                    return;
                }
                else if (v[right] < answer[right]){
                    return;
                }
                right--;
            }
        }
        return;
    }

    if (n > info[i]){
        vector<int> v2 = v;
        v2.push_back(info[i]+1);
        backtracking(n-(info[i]+1), info, i+1, aScore, lScore+10-i, v2);
    }
    
    vector<int> v1 = v;
    v1.push_back(0);
    if (info[i] == 0){
        backtracking(n, info, i+1, aScore, lScore, v1);
    }
    else{
        backtracking(n, info, i+1, aScore+10-i, lScore, v1);
    }
}

vector<int> solution(int n, vector<int> info) {
    backtracking(n, info, 0, 0, 0, {});
    
    if (maxAnswer == 0){
        answer.push_back(-1);
    }
    return answer;
}