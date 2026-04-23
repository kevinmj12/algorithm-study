#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int minTired = INT_MAX;

void backtracking(vector<int> picks, vector<string> minerals, 
                  int idx, int tired){
    if (idx >= minerals.size() || 
        accumulate(picks.begin(), picks.end(), 0) == 0){
        minTired = min(minTired, tired);
        return;
    }
    
    int nextTired = tired;
    int nextIdx = idx;
    
    if (picks[0] > 0){
        picks[0]--;
        for (int i = 0; i < 5; i++){
            if (nextIdx < minerals.size()){
                nextIdx++;
                nextTired++;
            }
            else{
                break;
            }
        }
        backtracking(picks, minerals, nextIdx, nextTired);
        picks[0]++;
        nextTired = tired;
        nextIdx = idx;
    }
    if (picks[1] > 0){
        picks[1]--;
        for (int i = 0; i < 5; i++){
            if (nextIdx < minerals.size()){
                if (minerals[nextIdx] == "diamond"){
                    nextTired += 5;
                }
                else{
                    nextTired++;
                }
                nextIdx++;
            }
            else{
                break;
            }
        }
        backtracking(picks, minerals, nextIdx, nextTired);
        picks[1]++;
        nextTired = tired;
        nextIdx = idx;
    }
    if (picks[2] > 0){
        picks[2]--;
        for (int i = 0; i < 5; i++){
            if (nextIdx < minerals.size()){
                if (minerals[nextIdx] == "diamond"){
                    nextTired += 25;
                }
                else if (minerals[nextIdx] == "iron"){
                    nextTired += 5;
                }
                else{
                    nextTired++;
                }
                nextIdx++;
            }
            else{
                break;
            }
        }
        backtracking(picks, minerals, nextIdx, nextTired);
        picks[2]++;
        nextTired = tired;
        nextIdx = idx;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    backtracking(picks, minerals, 0, 0);
    
    answer = minTired;
    
    return answer;
}