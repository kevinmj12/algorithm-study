#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

int apps[101][2];
map<int, int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    // 메모리를 입력받음
    for (int i = 1; i <= n; i++){
        cin >> apps[i][0];
    }
    // 비용을 입력받음
    for (int i = 1; i <= n; i++){
        cin >> apps[i][1];
    }

    // 배낭 문제와 비슷하다. 그런데 같은 방식으로 풀면 메모리 초과로 map을 사용하여 풂
    int answer = INT_MAX;
    for (int i = 1; i <= n; i++){
        int memory = apps[i][0];
        int cost = apps[i][1];
        
        // memory가 m보다 크다면 map에 넣을 필요가 없음
        if (memory >= m){
            answer = min(answer, cost);
            continue;
        }

        int dpSize = dp.size();
        auto it = dp.begin();
        for (int j = 0; j < dpSize; j++, it++){
            int target = it->first + memory;
            // 만약 target이 m보다 크다면 map에 넣을 필요가 없음
            if (target >= m){
                answer = min(answer, it->second+cost);
            }
            else{
                // dp에 찾고자 하는 값이 있는 경우
                if (dp.find(target) != dp.end()){
                    dp[target] = min(dp[target], it->second + cost);
                }
                // 찾고자 하는 값이 없는 경우 새로 insert
                else{
                    dp.insert({target, it->second + cost});
                }
            }

        }    
        // map에 반영
        if (dp.find(memory) != dp.end()){
            dp[memory] = min(dp[memory], cost);
        }
        else{
            dp.insert({memory, cost});
        }
    }
    
    cout << answer;
}