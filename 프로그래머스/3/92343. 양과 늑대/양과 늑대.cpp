#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> board[18];
bool visited[18];
int answer = 1;

void solve(vector<int> info, vector<int> next, int sCnt, int wCnt, int cur){
    if (info[cur] == 0){
        sCnt++;
    }
    else{
        wCnt++;
    }
    if (wCnt >= sCnt){
        return;
    }
    answer = max(answer, sCnt);
    
    visited[cur] = true;
    for (int i = 0; i < board[cur].size(); i++){
        next.push_back(board[cur][i]);
    }
    
    for (int i = 0; i < next.size(); i++){
        int n = next[i];
        if (visited[n]){
            continue;
        }
        if (info[i] == 0){
            solve(info, next, sCnt, wCnt, n);
        }
        else{
            solve(info, next, sCnt, wCnt, n);
        }
    }
    
    visited[cur] = false;
    for (int i = 0; i < board[cur].size(); i++){
        next.pop_back();
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {    
    for (int i = 0; i < edges.size(); i++){
        int p = edges[i][0];
        int s = edges[i][1];
        board[p].push_back(s);
    }
    
    solve(info, {}, 0, 0, 0);
    
    return answer;
}