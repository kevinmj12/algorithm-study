#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> buildings;
    long long answer = 0;

    for (int i = 0; i < n; i++){
        int height;
        cin >> height;

        while (!buildings.empty() && buildings.top() <= height){
            buildings.pop();
        }
        answer += buildings.size();
        buildings.push(height);
    }

    cout << answer;
}