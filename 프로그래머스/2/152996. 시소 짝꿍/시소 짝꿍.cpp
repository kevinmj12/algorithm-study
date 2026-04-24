#include <string>
#include <vector>
#include <map>

using namespace std;

bool weightsGraph[1001][1001];

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, int> weightsMap;
    for (int i = 0; i < weights.size(); i++){
        weightsMap[weights[i]]++;
    }
    
    for (int i = 0; i < weights.size(); i++){
        int left = weights[i];
        
        // 몸무게가 같은 경우
        weightsMap[weights[i]]--;
        answer += weightsMap[weights[i]];
        
        for (int j = 2; j <= 4; j++){
            for (int k = 2; k <= 4; k++){
                if (j == k){
                    continue;
                }
                if (weights[i] * j % k != 0){
                    continue;
                }
                answer += weightsMap[weights[i] * j / k];
            }
        }
    }
    
    return answer;
}