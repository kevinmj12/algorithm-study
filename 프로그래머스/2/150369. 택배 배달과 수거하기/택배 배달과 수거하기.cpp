#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dIdx = n-1;
    int pIdx = n-1;
    
    // 맨 끝이 0일 수도?
    while (dIdx >= 0 && deliveries[dIdx] == 0){
        dIdx--;
    }
    while (pIdx >= 0 && pickups[pIdx] == 0){
        pIdx--;
    }
    
    while (pIdx >= 0 || dIdx >= 0){
        answer += (max(pIdx, dIdx)+1) * 2;
        
        int c = cap;
        while (dIdx >= 0 && c >= deliveries[dIdx]){
            c -= deliveries[dIdx];
            deliveries[dIdx] = 0;
            dIdx--;
        }
        if (dIdx >= 0){
            deliveries[dIdx] -= c;
            c = 0;   
        }
        
        c = cap;
        while (pIdx >= 0 && c >= pickups[pIdx]){
            c -= pickups[pIdx];
            pickups[pIdx] = 0;
            pIdx--;
        }
        if (pIdx >= 0){
            pickups[pIdx] -= c;
            c = 0;   
        }
    }
    
    return answer;
}