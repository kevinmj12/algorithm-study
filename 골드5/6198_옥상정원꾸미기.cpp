#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<int> buildings;
    long long answer = 0;

    int N;
    cin >> N;
    
    while (N--){
        int h;
        cin >> h;
        if (buildings.empty()){
            buildings.push(h);
        }
        else{
            if (buildings.top() > h){
                answer+= buildings.size();
                buildings.push(h);
            }
            else{
                while (!buildings.empty() && buildings.top() <= h){
                    buildings.pop();
                }
                if (!buildings.empty()){
                    answer += buildings.size();
                }
                buildings.push(h);
            }
        }
    }
    cout << answer;
}