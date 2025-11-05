#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> warehouses(N, {0, 0});
    for (int i = 0; i < N; i++){
        cin >> warehouses[i][0] >> warehouses[i][1];
    }

    sort(warehouses.begin(), warehouses.end());

    stack<int> roof;
    int highestIdx = 0;
    roof.push(0);

    for (int i = 1; i < N; i++){
        if (warehouses[i][1] >= warehouses[highestIdx][1]){
            while (roof.top() != highestIdx){
                roof.pop();
            }
            roof.push(i);
            highestIdx = i;
        }
        else if (warehouses[i][1] < warehouses[highestIdx][1]){
            while (warehouses[roof.top()][1] <= warehouses[i][1]){
                roof.pop();
            }
            roof.push(i);
        }
    }

    int answer = 0;
    int size = roof.size()-1;
    while (true){
        int first = roof.top();
        if (first == highestIdx){
            answer += warehouses[first][1];
            break;
        }
        roof.pop();
        int second = roof.top();

        int diff = warehouses[first][0] - warehouses[second][0];
        answer += diff * warehouses[first][1];
    }

    size = roof.size()-1;
    for (int i = 0; i < size; i++){
        int first = roof.top();
        roof.pop();

        int second = roof.top();

        int diff = warehouses[first][0] - warehouses[second][0];
        answer += diff * warehouses[second][1];
    }

    cout << answer;
}