#include <iostream>
#include <stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int answer = 0;
    stack<int> buildings;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        if (y == 0){
            while (!buildings.empty()){
                buildings.pop();
            }
        }
        else if (buildings.empty() || buildings.top() < y){
            buildings.push(y);
            answer++;
        }
        else{
            while (!buildings.empty() && buildings.top() > y){
                buildings.pop();
            }
            if (buildings.empty() || buildings.top() < y){
                answer++;
            }
            buildings.push(y);
        }
    }

    cout << answer;
}