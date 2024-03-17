#include <iostream>
#include <queue>
#include <vector>
#define MAX 300000
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jewels;
    priority_queue<int, vector<int>, greater<int>> bags;
    priority_queue<int> values;


    while (N--){
        int M, V;
        cin >> M >> V;

        jewels.push({M, V});
    }

    while (K--){
        int C;
        cin >> C;

        bags.push(C);
    }

    long long answer = 0;
    
    while(!bags.empty() && !jewels.empty()){
        if (bags.top() < jewels.top().first){
            bags.pop();
        }
        else{
            while (!jewels.empty() && bags.top() >= jewels.top().first){
                values.push(jewels.top().second);
                jewels.pop();
            }
            answer += values.top();
            values.pop();
        }
    }

    cout << answer;
}