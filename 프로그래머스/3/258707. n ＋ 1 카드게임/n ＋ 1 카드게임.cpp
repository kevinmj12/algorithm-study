#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int able[1000];

int solution(int coin, vector<int> cards) {    
    int n = cards.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < n/3; i++){
        int cur = cards[i];
        able[cur] = 1;
        if (able[n+1-cur]){
            pq.push(0);
        }
    }
    
    int round = 1;
    while (true){
        // 뽑을 카드가 없다면 종료
        if (round == n/3+1){
            break;
        }
        
        int idx = n/3 + (round-1)*2;
        int target1 = cards[idx];
        int target2 = cards[idx+1];
        
        able[target1] = 2;
        able[target2] = 2;
        
        if (able[n+1-target1]){
            pq.push(able[n+1-target1]);
        }
        if (able[n+1-target2]){
            pq.push(able[n+1-target2]);
        }
                
        // 버릴 카드가 없다면 종료
        if (pq.empty() || coin < pq.top()){
            break;
        }
        
        // 카드 버리기
        coin -= pq.top();
        pq.pop();
        
        round++;
    }
    
    return round;
}