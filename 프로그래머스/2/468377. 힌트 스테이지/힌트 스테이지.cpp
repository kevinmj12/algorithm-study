#include <string>
#include <vector>
#include <climits>

using namespace std;

int minCost = INT_MAX;

void backtracking(vector<vector<int>> cost, int round, int totalCost,
                  vector<vector<int>> hint, vector<int> curHints){
    int roundHint = min(curHints[round], int(cost[0].size()-1));
    totalCost += cost[round-1][roundHint];
    
    // 종료 조건
    if (round == cost.size()){
        minCost = min(minCost, totalCost);
        return;
    }

    
    // 힌트권을 구매하지 않음
    backtracking(cost, round+1, totalCost, hint, curHints);
        
    // 힌트권을 구매함
    totalCost += hint[round-1][0];
    for (int i = 1; i < hint[round-1].size(); i++){
        curHints[hint[round-1][i]]++;
    }
    backtracking(cost, round+1, totalCost, hint, curHints);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    
    vector<int> curHints;
    for (int i = 0; i <= cost.size(); i++){
        curHints.push_back(0);
    }
    
    backtracking(cost, 1, 0, hint, curHints);
    
    answer = minCost;
    
    return answer;
}