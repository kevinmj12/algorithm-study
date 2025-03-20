#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool selected[31];

bool canPassword(int n, vector<int> password, vector<vector<int>> q, vector<int> ans){
    for (int i = 0; i < q.size(); i++){
        int targetCounts = 0;
        for (int j = 0; j < 5; j++){
            int target = q[i][j];
            for (int k = 0; k < 5; k++){
                if (target == password[k]){
                    targetCounts++;
                    break;
                }
            }
        }
        if (targetCounts != ans[i]){
            return false;
        }
    }
    return true;
}

void backtracking(int n, vector<int> vec, vector<vector<int>> q, vector<int> ans){
    if (vec.size() == 5){
        if (canPassword(n, vec, q, ans)){
            answer++;
        }
        return;
    }
    
    int i = 1;
    if (vec.size()){
        i = vec.back()+1;
    }
    for (i; i <= n; i++){
        if (!selected[i]){
            selected[i] = true;
            vec.push_back(i);
            backtracking(n, vec, q, ans);
            vec.pop_back();
            selected[i] = false;
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    backtracking(n, {}, q, ans);    
    
    return answer;
}