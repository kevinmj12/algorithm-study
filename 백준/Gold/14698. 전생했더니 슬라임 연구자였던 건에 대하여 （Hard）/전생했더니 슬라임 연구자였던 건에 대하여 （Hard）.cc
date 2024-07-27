#include <iostream>
#include <queue>
using namespace std;

#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;

        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;

        for (int i = 0; i < n; i++){
            unsigned long long slime;
            cin >> slime;
            pq.push(slime);
        }

        unsigned long long answer = 1;
        while (pq.size() > 1){
            unsigned long long a = pq.top();
            pq.pop();
            unsigned long long b = pq.top();
            pq.pop();

            answer = (a * b % MOD) * answer % MOD;
            pq.push(a * b);
        }

        
        cout << answer << "\n";
    }
}