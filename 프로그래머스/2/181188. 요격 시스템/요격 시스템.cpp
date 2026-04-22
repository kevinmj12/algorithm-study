#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end()
         , [](vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
        );
    
    int point = 0;
    for (int i = 0; i < targets.size(); i++){
        if (point <= targets[i][0]){
            answer++;
            point = targets[i][1];
        }
        // cout << targets[i][0] << " " << targets[i][1] << "\n";
    }
    
    return answer;
}